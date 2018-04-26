#include "stdafx.h"
#include "App.h"
#include <iostream>
#include "DestroyerRoad.h"
#include "CreationRoad.h"
#include "NeutralRoad.h"

void App::createRoads(const int timer)
{
   const auto o1west = new DestroyerRoad(80, timer);
   const auto o1east = new CreationRoad(80, timer, 10);
   roads->push_back(o1west);
   roads->push_back(o1east);

   const auto s1south = new DestroyerRoad(60, timer+5);
   const auto s1north = new CreationRoad(60, timer+5, 30);
   roads->push_back(s1north);
   roads->push_back(s1south);

   const auto s2south = new DestroyerRoad(40, timer);
   const auto s2north = new CreationRoad(40, timer, 60);
   roads->push_back(s2south);
   roads->push_back(s2north);

   const auto l1east = new DestroyerRoad(30, timer+5);
   const auto l1west = new CreationRoad(30, timer+5, 10);
   roads->push_back(l1east);
   roads->push_back(l1west);

   const auto n2south = new DestroyerRoad(40, timer+10);
   const auto n2north = new CreationRoad(40, timer+10, 20);
   roads->push_back(n2north);
   roads->push_back(n2south);

   const auto n1north = new DestroyerRoad(60, timer+15);
   const auto n1south = new CreationRoad(60, timer+15, 20);
   roads->push_back(n1north);
   roads->push_back(n1south);

   const auto c1west = new NeutralRoad(60, timer+10);
   const auto c1east = new NeutralRoad(60, timer+15);
   roads->push_back(c1west);
   roads->push_back(c1east);

   o1east->connectRoads(Road::RoadPercent(s1south, 1), Road::RoadPercent(n1north, 1), Road::RoadPercent(c1east, 8));
   n1south->connectRoads(Road::RoadPercent(c1east, 8), Road::RoadPercent(o1west, 1), Road::RoadPercent(s1south, 1));
   s1north->connectRoads(Road::RoadPercent(c1east, 8), Road::RoadPercent(n1north, 1), Road::RoadPercent(o1west, 1));
   c1west->connectRoads(Road::RoadPercent(o1west, 4), Road::RoadPercent(n1north, 3), Road::RoadPercent(s1south, 3));

   c1east->connectRoads(Road::RoadPercent(l1west, 4), Road::RoadPercent(n2north, 3), Road::RoadPercent(s2south, 3));
   n2south->connectRoads(Road::RoadPercent(l1east, 4), Road::RoadPercent(c1west, 3), Road::RoadPercent(s2south, 3));
   s2north->connectRoads(Road::RoadPercent(l1west, 4), Road::RoadPercent(s2south, 3), Road::RoadPercent(c1west, 3));
   l1west->connectRoads(Road::RoadPercent(n2north, 4), Road::RoadPercent(c1east, 3), Road::RoadPercent(s2south, 3));

}

App::App() : userIO(new UserIO())
{
   clock = new Clock(userIO->getExecTime());
   //clock->connectNotify(std::bind(&App::notifyAll, this));

   const auto semaphoreTime = userIO->getSemaphoreTime();

   roads = new List<Road*>(14);
   
   createRoads(semaphoreTime);
}

App::~App()
{
   roads->clear();
   events->clear();
   
   delete events;
   delete roads;
   delete clock;
   delete userIO;
}

void App::notifyAll(const int time)
{
   for (int i = 0; i < roads->getSize(); i++)   
      roads->operator[](i)->getNotify(time);
}

void App::addEvent(const std::string description)
{
   events->push_back(new Event(clock->getCurrentTimeFormated(), description));
}

#include "App.h"
#include "DestroyerRoad.h"
#include "CreationRoad.h"
#include "NeutralRoad.h"
#include <iostream>

void App::createRoads(const int timer)
{
   const auto o1west = new DestroyerRoad(80, 2000, timer);
   const auto o1east = new CreationRoad(80, 2000, timer, 10);
   roads.push_back(o1west);
   roads.push_back(o1east);
   connectRoadEvent(o1west);
   connectRoadEvent(o1east);

   const auto s1south = new DestroyerRoad(60, 500, timer+5);
   const auto s1north = new CreationRoad(60, 500, timer+5, 30);
   roads.push_back(s1north);
   roads.push_back(s1south);
   connectRoadEvent(s1south);
   connectRoadEvent(s1north);

   const auto s2south = new DestroyerRoad(40, 500, timer);
   const auto s2north = new CreationRoad(40, 500, timer, 60);
   roads.push_back(s2south);
   roads.push_back(s2north);
   connectRoadEvent(s2south);
   connectRoadEvent(s2north);

   const auto l1east = new DestroyerRoad(30, 400, timer+5);
   const auto l1west = new CreationRoad(30, 400, timer+5, 10);
   roads.push_back(l1east);
   roads.push_back(l1west);
   connectRoadEvent(l1east);
   connectRoadEvent(l1west);

   const auto n2south = new DestroyerRoad(40, 500, timer+10);
   const auto n2north = new CreationRoad(40, 500, timer+10, 20);
   roads.push_back(n2north);
   roads.push_back(n2south);
   connectRoadEvent(n2south);
   connectRoadEvent(n2north);

   const auto n1north = new DestroyerRoad(60, 500, timer+15);
   const auto n1south = new CreationRoad(60, 500, timer+15, 20);
   roads.push_back(n1north);
   roads.push_back(n1south);
   connectRoadEvent(n1north);
   connectRoadEvent(n1south);

   const auto c1west = new NeutralRoad(60, 300, timer+10);
   const auto c1east = new NeutralRoad(60, 300, timer+15);
   roads.push_back(c1west);
   roads.push_back(c1east);
   connectRoadEvent(c1west);
   connectRoadEvent(c1east);

   o1east->connectRoads(Road::RoadPercent(s1south, 1), Road::RoadPercent(n1north, 1), Road::RoadPercent(c1east, 8));
   n1south->connectRoads(Road::RoadPercent(c1east, 8), Road::RoadPercent(o1west, 1), Road::RoadPercent(s1south, 1));
   s1north->connectRoads(Road::RoadPercent(c1east, 8), Road::RoadPercent(n1north, 1), Road::RoadPercent(o1west, 1));
   c1west->connectRoads(Road::RoadPercent(o1west, 4), Road::RoadPercent(n1north, 3), Road::RoadPercent(s1south, 3));

   c1east->connectRoads(Road::RoadPercent(l1west, 4), Road::RoadPercent(n2north, 3), Road::RoadPercent(s2south, 3));
   n2south->connectRoads(Road::RoadPercent(l1east, 4), Road::RoadPercent(c1west, 3), Road::RoadPercent(s2south, 3));
   s2north->connectRoads(Road::RoadPercent(l1west, 4), Road::RoadPercent(s2south, 3), Road::RoadPercent(c1west, 3));
   l1west->connectRoads(Road::RoadPercent(n2north, 4), Road::RoadPercent(c1east, 3), Road::RoadPercent(s2south, 3));

}

void App::connectRoadEvent(Road* road)
{
   //road->connectAddEvent([this](const std::string descp) { addEvent(descp); });
}

App::App() : userIO(new UserIO()), roads(Lista<Road*>(14)), events(Lista<Event*>(10))
{
   clock = new Clock(userIO->getExecTime());
   clock->connectNotify(std::bind(&App::notifyAll, this, 1));
   //clock->connectNotify([this](int elapsedMilli) { notifyAll(elapsedMilli);  });

   const auto semaphoreTime = userIO->getSemaphoreTime();
   createRoads(semaphoreTime);
}

App::~App()
{
   roads.clear();
   events.clear();
   
   delete clock;
   delete userIO;
}

void App::notifyAll(const int time) 
{
   for (int i = 0; i < roads.getSize(); i++)   
      roads.operator[](i)->getNotify(time);
}

void App::addEvent(std::string description)
{
   events.push_back(new Event(clock->getCurrentTimeFormated(), description));
}

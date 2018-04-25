#include "stdafx.h"
#include "App.h"
#include <iostream>
#include "DestroyerRoad.h"
#include "CreationRoad.h"
#include "NeutralRoad.h"

void App::createRoads(const int timer)
{
   const auto o1west = new DestroyerRoad(80, 2000, timer);
   const auto o1east = new CreationRoad(80, 2000, timer, 10);
   roads.push_back(o1west);
   roads.push_back(o1east);

   const auto s1south = new DestroyerRoad(60, 500, timer);
   const auto s1north = new CreationRoad(60, 500, timer, 30);
   roads.push_back(s1north);
   roads.push_back(s1south);

   const auto s2south = new DestroyerRoad(40, 500, timer);
   const auto s2north = new CreationRoad(40, 500, timer, 60);
   roads.push_back(s2south);
   roads.push_back(s2north);

   const auto l1east = new DestroyerRoad(30, 400, timer);
   const auto l1west = new CreationRoad(30, 400, timer, 10);
   roads.push_back(l1east);
   roads.push_back(l1west);

   const auto n2south = new DestroyerRoad(40, 500, timer);
   const auto n2north = new CreationRoad(40, 500, timer, 20);
   roads.push_back(n2north);
   roads.push_back(n2south);

   const auto n1north = new DestroyerRoad(60, 500, timer);
   const auto n1south = new CreationRoad(60, 500, timer, 20);
   roads.push_back(n1north);
   roads.push_back(n1south);

   const auto c1west = new NeutralRoad(60, 300, timer);
   const auto c1east = new NeutralRoad(60, 300, timer);
   roads.push_back(c1west);
   roads.push_back(c1east);

   o1east->connectRoad(s1south);
   o1east->connectRoad(c1east);
   o1east->connectRoad(n1north);

   s1north->connectRoad(c1east);
   s1north->connectRoad(n1north);
   s1north->connectRoad(o1west);

   s2north->connectRoad(l1east);
   s2north->connectRoad(n2south);
   s2north->connectRoad(c1west);

   l1west->connectRoad(n2south);
   l1west->connectRoad(c1west);
   l1west->connectRoad(s2south);

   n2south->connectRoad(c1west);
   n2south->connectRoad(s2south);
   n2south->connectRoad(l1east);

   n1south->connectRoad(o1west);
   n1south->connectRoad(s1south);
   n1south->connectRoad(c1east);

   c1west->connectRoad(n1north);
   c1west->connectRoad(o1west);
   c1west->connectRoad(s1south);

   c1east->connectRoad(s2south);
   c1east->connectRoad(l1east);
   c1east->connectRoad(n2north);
}

App::App() : userIO(new UserIO())
{
   clock = new Clock(userIO->getExecTime());
   //clock->connectNotify(std::bind(&App::notifyAll, this));

   const auto semaphoreTime = userIO->getSemaphoreTime();
   
   createRoads(semaphoreTime);
}

App::~App()
{
   roads.clear();
   delete clock;
   delete userIO;
}

void App::notifyAll(const int time)
{
   for (auto road : roads)
      road->getNotify(time);  
}

void App::addEvent(const std::string description)
{
   events.push(new Event(clock->getCurrentTimeFormated(), description));
}

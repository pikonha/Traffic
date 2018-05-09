#include "App.h"
#include "DestroyerRoad.h"
#include "CreationRoad.h"
#include "NeutralRoad.h"

void App::createRoads(const int timer)
{
   const auto o1west = new DestroyerRoad("O1west", 80, 2000, timer);
   const auto o1east = new CreationRoad("O1east", 80, 2000, timer, 10);
   roads.push_back(o1east);
   roads.push_back(o1west);

   const auto s1south = new DestroyerRoad("S1south", 60, 500, timer+4);
   const auto s1north = new CreationRoad("S1north", 60, 500, timer+4, 30);
   roads.push_back(s1north);
   roads.push_back(s1south);

   const auto s2south = new DestroyerRoad("S2south",40, 500, timer);
   const auto s2north = new CreationRoad("S2north", 40, 500, timer, 60);
   roads.push_back(s2north);
   roads.push_back(s2south);

   const auto l1east = new DestroyerRoad("L1east", 30, 400, timer+4);
   const auto l1west = new CreationRoad("L1west", 30, 400, timer+4, 10);
   roads.push_back(l1west);
   roads.push_back(l1east);

   const auto n2south = new DestroyerRoad("N2south", 40, 500, timer+8);
   const auto n2north = new CreationRoad("N2north",40, 500, timer+8, 20);
   roads.push_back(n2north);
   roads.push_back(n2south);

   const auto n1north = new DestroyerRoad("N1north", 60, 500, timer+12);
   const auto n1south = new CreationRoad("N1south", 60, 500, timer+12, 20);
   roads.push_back(n1south);
   roads.push_back(n1north);

   const auto c1west = new NeutralRoad("C1west", 60, 300, timer+8);
   const auto c1east = new NeutralRoad("C1east", 60, 300, timer+12);
   roads.push_back(c1west);
   roads.push_back(c1east);

   o1east->connectRoads(Road::RoadPercent(s1south, 1), Road::RoadPercent(n1north, 1), Road::RoadPercent(c1east, 8));
   s1north->connectRoads(Road::RoadPercent(c1east, 8), Road::RoadPercent(n1north, 1), Road::RoadPercent(o1west, 1));
   s2north->connectRoads(Road::RoadPercent(l1west, 4), Road::RoadPercent(s2south, 3), Road::RoadPercent(c1west, 3));
   l1west->connectRoads(Road::RoadPercent(n2north, 4), Road::RoadPercent(c1east, 3), Road::RoadPercent(s2south, 3));
   n2north->connectRoads(Road::RoadPercent(l1east, 4), Road::RoadPercent(c1west, 3), Road::RoadPercent(s2south, 3));
   n1south->connectRoads(Road::RoadPercent(c1east, 8), Road::RoadPercent(o1west, 1), Road::RoadPercent(s1south, 1));   
   c1west->connectRoads(Road::RoadPercent(o1west, 4), Road::RoadPercent(n1north, 3), Road::RoadPercent(s1south, 3));
   c1east->connectRoads(Road::RoadPercent(l1west, 4), Road::RoadPercent(n2north, 3), Road::RoadPercent(s2south, 3));
}


App::App() : userIO(new UserIO()), roads(Lista<Road*>(14))
{
   clock = new Clock();
   clock->connectNotify([this](int timeEllapsed)
   {
      notifyAll(timeEllapsed);
   });
   createRoads(userIO->getSemaphoreTime());
}

App::~App()
{
   roads.clear();
   
   delete clock;
   delete userIO;
}

void App::notifyAll(const int time) const
{
   userIO->printEventPartition(clock->timeView(time));

   for (int i = 0; i < roads.getSize(); i++) {
      auto road = roads[i];
      road->getNotify(time);
      userIO->addLog(road->getLogger());
      userIO->addLogToTable(road->getName(), road->getLogger());
   }

   userIO->printTotalLogs();
   
}

void App::startApplication() const
{
   clock->startClock(userIO->getExecTime());
}


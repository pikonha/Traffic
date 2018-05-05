#include "Road.h"
#include "Car.h"

Road::Road(const int _vel, const int timer) :
   velocity(_vel),
   semaphore(new Semaphore(timer)),
   connectedRoads(Lista<Road*>(3)),
   cars(LinkedQueue<Car*>())
{}

void Road::connectRoads(const RoadPercent r1, const RoadPercent r2, const RoadPercent r3)
{
   for (int i = 0; i < r1.percent; i++)
      connectedRoads.push_back(r1.road);

   for (int i = 0; i < r2.percent; i++)
      connectedRoads.push_back(r2.road);

   for (int i = 0; i < r3.percent; i++)
      connectedRoads.push_back(r3.road);
}

bool Road::recieveCar(Car* car)
{  

//    addEvent("Full road.");
   return false;
}



#include "stdafx.h"
#include "Road.h"
#include "Car.h"

void Road::connectRoad(Road* road)
{
   connectedRoads.push_back(road);
}

bool Road::recieveCar(Car* car)
{
   if (capacity - car->getLength() > 0)
   {
      cars.push(car);
      capacity -= car->getLength();
      addEvent("Car changing road.");
      return true;
   }

   addEvent("Full road.");
   return false;
}



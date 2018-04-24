#include "stdafx.h"
#include "DestroyerRoad.h"
#include "Car.h"


void DestroyerRoad::deleteCar()
{
   const auto car = cars.front();
   cars.pop();

   addEvent("Car destroyed");

   delete car;
}


#include "stdafx.h"
#include "CreationRoad.h"
#include "Car.h"

void CreationRoad::createCar()
{
   cars.push(new Car());

   addEvent("New car created");
}

#include "stdafx.h"
#include "CreationRoad.h"
#include "Car.h"

void CreationRoad::createCar()
{
   cars.push(new Car(velocity));

   addEvent("New car created");
}

void CreationRoad::getNotify(const int time)
{
   if (frequence % time == 0)
      createCar();
   if (semaphore->getTimer() % time == 0)
      semaphore->changeState();
}

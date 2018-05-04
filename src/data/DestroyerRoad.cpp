#include "DestroyerRoad.h"
#include "LinkedQueue.h"
#include "Car.h"

void DestroyerRoad::deleteCar()
{
   delete cars.dequeue();

   addEvent("Car destroyed");

}

void DestroyerRoad::getNotify(const int time)
{
   if (semaphore->getTimer() % time == 0)
      semaphore->changeState();
}


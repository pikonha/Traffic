#include "DestroyerRoad.h"
#include "LinkedQueue.h"
#include "Car.h"

void DestroyerRoad::deleteCar()
{
   cars.dequeue();
   logger.addLog(CAR_DELETED);
}

void DestroyerRoad::checkFirstCar()
{
   if (cars.front().getWalked() >= length)
      deleteCar();
}

void DestroyerRoad::getNotify(const int time)
{
   if (semaphore->getTimer() % time == 0)
      semaphore->changeState();

   if (semaphore->isOpen())
   {
      checkFirstCar();
      moveCars();
   }
     
}


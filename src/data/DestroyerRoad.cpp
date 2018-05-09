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
   if (cars.empty()) return;

   if (cars.front().getWalked() >= length)
      deleteCar();
}

void DestroyerRoad::moveCars()
{ 
   checkFirstCar();

   try
   {
      if (cars.front().getWalked() < length)
         cars.moveCars();
   }
   catch(...) {}
   
}

void DestroyerRoad::getNotify(const int time)
{
   if (time % semaphore->getTimer() == 0)
      semaphore->changeState();

   moveCars();   
     
}


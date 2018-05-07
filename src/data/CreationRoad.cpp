
#include "CreationRoad.h"
#include "Car.h"

void CreationRoad::createCar()
{
   if ( cars.getCapacity() >= 8) {
      recieveCar(new Car(velocity));
      logger.addLog(CAR_CREATED);
   }
   else
      logger.addLog(CAR_BLOCKED);
}

void CreationRoad::getNotify(const int time)
{
   if (semaphore->getTimer() <= time)
      semaphore->changeState();
   
   if (semaphore->isOpen())
      moveCars();

   if (frequence % time == 0)
      createCar();


}

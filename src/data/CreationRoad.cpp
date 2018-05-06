
#include "CreationRoad.h"
#include "Car.h"

Car* CreationRoad::createCar()
{
   recieveCar(new Car(velocity));
   logger.addLog(CAR_CREATED);
}

void CreationRoad::getNotify(const int time)
{
   if (frequence % time == 0)
      createCar();
   if (semaphore->getTimer() % time == 0)
      semaphore->changeState();

}

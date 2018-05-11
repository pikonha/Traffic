
#include "CreationRoad.h"
#include "Car.h"

void CreationRoad::createCar()
{
   if ( cars.getCapacity() >= 8) {
      recieveCar(new Car(velocity), false);
      logger.addLog(CAR_CREATED);
   }
   else
      logger.addLog(CAR_BLOCKED);
}


void CreationRoad::getNotify(const int time)
{
   if (time % frequence == 0)
      createCar();

   moveCars();

}

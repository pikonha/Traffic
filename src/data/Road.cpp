#include "Road.h"
#include "Car.h"

void Road::moveCars()
{
   try {
      auto car = cars.front();
      if (car->getWalked() >= length)
      {
         if (semaphore.isOpen()) {
            const auto carOption = car->getOption();

            try
            {
               if (connectedRoads[carOption]->recieveCar(car))
                  removeCar();

            }
            catch (...)
            {
               logger.addLog(CAR_BLOCKED);
            }
         }
      }
      else if (car)
         cars.moveCars();
   }
   catch (...)
   {}      
}

Road::Road(const std::string _name, const int _vel, const int _length, Semaphore& _semaphore) :
   name(_name),
   velocity(_vel),
   length(_length),
   semaphore(_semaphore),
   logger(Logger()),   
   cars(_length),
   connectedRoads(Lista<Road*>(10))
{}

void Road::connectRoads(const RoadPercent r1, const RoadPercent r2, const RoadPercent r3)
{
   for (int i = 0; i < r1.percent; i++)
      connectedRoads.push_back(r1.road);

   for (int i = 0; i < r2.percent; i++)
      connectedRoads.push_back(r2.road);

   for (int i = 0; i < r3.percent; i++)
      connectedRoads.push_back(r3.road);
}

void Road::getNotify(const int time)
{
   moveCars();
}

bool Road::recieveCar(Car* car, bool addLog)
{
   try
   {
      cars.enqueue(car);

      car->setSpeed(velocity);

      if (addLog)
         logger.addLog(CAR_ENTRY);
      return true;
   }
   catch (...)
   {
      return false;
   }
   
}

bool Road::removeCar()
{
   try
   {
      cars.dequeue();   
      logger.addLog(CAR_LEFT);
      return true;
   }
   catch (...)
   {
      return false;
   }   
}



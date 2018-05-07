#include "Road.h"
#include "Car.h"

void Road::moveCars()
{
   try {
      auto car = cars.front();
      if (car.getWalked() >= length)
      {
         const auto carOption = car.getOption();

         try
         {
            if (connectedRoads[carOption]->recieveCar(&car))
               removeCar();
            
         }catch(...)
         {
            logger.addLog(CAR_BLOCKED);
         }         
      }     
   }
   catch (...)
   {}      
}

Road::Road(const int _vel, const int _length, const int timer) :
   velocity(_vel),
   length(_length),
   semaphore(new Semaphore(timer)),
   logger(Logger()),   
   cars(_length),
   connectedRoads(Lista<Road*>(3))
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

bool Road::recieveCar(Car* car)
{
   try
   {
      cars.enqueue(*car);

      car->setSpeed(velocity);

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



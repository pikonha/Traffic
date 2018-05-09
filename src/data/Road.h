#pragma once
#ifndef INCLUDED_ROAD_H
#define INCLUDED_ROAD_H

#include "Semaphore.h"
#include "CarQueue.h"
#include "Lista.h"
#include "Logger.h"

class Car;

class Road
{
protected:
   std::string name;
   int velocity;
   int length;

   Semaphore* semaphore;

   Logger logger;

   CarQueue cars;
   Lista<Road*> connectedRoads;

   virtual void moveCars();
   bool removeCar();
   bool recieveCar(Car* car);  
public:
   virtual ~Road() { delete semaphore; }
   Road(const std::string _name, const int _vel, const int _length, const int timer);

   //////////////////////////////////////////////////////////
   struct RoadPercent
   {
      Road* road;
      int percent;

      RoadPercent(Road* _road, const int _percent)
      {
         road = _road;
         percent = _percent;
      }
   };
   /////////////////////////////////////////////////////////

   void connectRoads(const RoadPercent, const RoadPercent, const RoadPercent);

   virtual void getNotify(const int time) = 0;

   int getCapacity() const { return cars.getCapacity(); }
   Logger getLogger() const { return logger; }
   std::string getName() const { return name; }

};

#endif
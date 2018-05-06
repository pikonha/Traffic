#ifndef INCLUDED_ROAD_H
#define INCLUDED_ROAD_H

#pragma once

#include <functional>
#include "Semaphore.h"
#include "LinkedQueue.h"
#include "Lista.h"
#include "Logger.h"

class Car;

class Road
{
protected:
   int velocity;
   int length;
   int capacity;

   Semaphore* semaphore;

   Logger logger;

   LinkedQueue<Car*> cars;
   Lista<Road*> connectedRoads;

   void moveCars();
   bool removeCar();
   bool recieveCar(Car* car);  

   bool checkCarFit(Car* car) const;
public:
   virtual ~Road() { delete semaphore; }
   Road(const int _vel, const int _length, const int timer);

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

   int getCapacity() const { return capacity; }
   Logger getLogger() const { return logger; }

};

#endif
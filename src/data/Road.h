#ifndef INCLUDED_ROAD_H
#define INCLUDED_ROAD_H

#pragma once

#include <functional>
#include <list>
#include "Semaphore.h"
#include "Fila.h"
#include "Lista.h"

class Car;

class Road
{
protected:
   int velocity;

   Semaphore* semaphore;

   Fila<Car*> cars;
   Lista<Road*> connectedRoads;

   std::function<void(std::string description)> addEvent;

public:
   virtual ~Road() { delete semaphore; }
   Road(const int _vel,  const int timer);

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

   void connectAddEvent(std::function<void(std::string)> _addEvent) { addEvent = _addEvent; }

   void connectRoads(const RoadPercent, const RoadPercent, const RoadPercent);
   
   bool recieveCar(Car* car);

   virtual void getNotify(const int time) = 0;

};

#endif
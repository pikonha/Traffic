#ifndef INCLUDED_ROAD_H
#define INCLUDED_ROAD_H

#pragma once

#include <functional>
#include <list>
#include "Semaphore.h"
#include "Queue.h"
#include "List.h"

class Car;

class Road
{
protected:
   int velocity;

   Semaphore* semaphore;

   Queue<Car*> cars;   
   List<Road*> connectedRoads;

   std::function<void(std::string description)> addEvent;

public:
   virtual ~Road() { delete semaphore; }
   Road(const int _vel, const int timer) : velocity(_vel), semaphore(new Semaphore(timer)) {}

   void connectAddEvent(const std::function<void(std::string)> _addEvent) { addEvent = _addEvent; }

   void connectRoad(Road* road);
   
   bool recieveCar(Car* car);

   virtual void getNotify(const int time) = 0;

};

#endif
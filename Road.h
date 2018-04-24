#ifndef INCLUDED_ROAD_H
#define INCLUDED_ROAD_H

#pragma once
#include <queue>
#include <functional>
#include <list>
#include "Semaphore.h"

class Car;

class Road
{
protected:
   double velocity;
   double length;

   std::queue<Car*> cars;

   Semaphore* semaphore;

   std::list<Road*> connectedRoads;

   std::function<void(std::string description)> addEvent;

public:
   Road(const double _vel, const double _length) : velocity(_vel), length(_length) {}
   virtual ~Road() { delete semaphore; }

   void connectAddEvent(const std::function<void(std::string)> _addEvent) { addEvent = _addEvent; }
};

#endif
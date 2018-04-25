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
   double length;
   double velocity;

   Semaphore* semaphore;

   std::queue<Car*> cars;   
   std::list<Road*> connectedRoads;

   std::function<void(std::string description)> addEvent;

public:
   virtual ~Road() { delete semaphore; }
   Road(const double _length, const double _vel, const int timer) : length(_length), velocity(_vel), semaphore(new Semaphore(timer)) {}   

   void connectAddEvent(const std::function<void(std::string)> _addEvent) { addEvent = _addEvent; }

   void connectRoad(Road* road);
   
   virtual void getNotify(const int time) = 0;

};

#endif
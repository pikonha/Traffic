#ifndef INCLUDED_ROAD_H
#define INCLUDED_ROAD_H

#pragma once
#include <queue>
#include <functional>

class Car;

class Road
{
protected:
   double velocity;
   double length;

   std::queue<Car*> cars;

   std::function<void(std::string description)> addEvent;

public:
   Road(const double _vel, const double _length) : velocity(_vel), length(_length) {}
   virtual ~Road() = default;

   void connectAddEvent(const std::function<void(std::string)> _addEvent) { addEvent = _addEvent; }
};

#endif
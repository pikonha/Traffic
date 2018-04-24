#ifndef INCLUDED_ROAD_H
#define INCLUDED_ROAD_H

#pragma once
#include <queue>
#include <functional>

class Car;

class Road
{
protected:
   int velocity;
   int length;

   std::queue<Car*> cars;


   std::function<void(std::string description)> addEvent;

public:
   Road(const int _vel, const int _length);
   virtual ~Road();

   void connectAddEvent(const std::function<void(std::string)> _addEvent) { addEvent = _addEvent; }
};

#endif
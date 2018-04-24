#ifndef INCLUDED_ROAD_H
#define INCLUDED_ROAD_H

#pragma once
#include <queue>
#include "Semaphore.h"

class Car;

class Road
{
   int velocity;
   int length;
   std::queue<Car*> cars;

   Semaphore* semaphore;
public:
   Road(const int _vel, const int _length, const double semaphoreTimer);
   ~Road();
};

#endif
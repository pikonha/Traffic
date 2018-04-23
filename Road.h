#ifndef INCLUDED_ROAD_H
#define INCLUDED_ROAD_H

#pragma once
#include "Queue.h"

class Car;

class Road
{
   int velocity;
   int length;
   Queue<Car*> cars;

public:
   Road();
   ~Road();
};

#endif
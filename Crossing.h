#ifndef INCLUDED_CROSSING_H
#define INCLUDED_CROSSING_H

#pragma once
#include "Highway.h"

class Crossing
{
   Highway* highway1;
   Highway* highway2;
  
public:
   Crossing(const double semaphoreTimer);
   ~Crossing();
};

#endif
#ifndef INCLUDED_CROSSING_H
#define INCLUDED_CROSSING_H

#pragma once
#include "Highway.h"

class Crossing
{
   Highway* highway1;
   Highway* highway2;
   Highway* highway3;
   Highway* highway4;
  
public:
   Crossing(const double semaphoreTimer);
   ~Crossing();

   void notify() const;
};

#endif
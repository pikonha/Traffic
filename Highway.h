#ifndef INCLUDED_HIGHWAY_H
#define INCLUDED_HIGHWAY_H

#pragma once
#include "Semaphore.h"
#include "Road.h"

class Highway
{
   Road* road1;
   Road* road2;

   Semaphore* semaphore;
public:
   Highway(const double vel1, const double lenght1, const double vel2, const double lenght2, const double semaphoreTimer);
   ~Highway();
};

#endif
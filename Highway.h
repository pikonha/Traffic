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
   Highway(const double semaphoreTimer);
   ~Highway();
};

#endif
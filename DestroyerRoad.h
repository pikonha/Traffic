#ifndef INCLUDED_DESTROYERROAD_H
#define INCLUDED_DESTROYERROAD_H

#pragma once
#include "Road.h"

class DestroyerRoad : public Road
{
   void deleteCar();

public:
   ~DestroyerRoad() = default;
   DestroyerRoad(const int _vel, const int _length, const double semaphoreTimer) : Road(_vel, _length, semaphoreTimer) {}  

};

#endif
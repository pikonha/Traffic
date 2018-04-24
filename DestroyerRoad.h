#ifndef INCLUDED_DESTROYERROAD_H
#define INCLUDED_DESTROYERROAD_H

#pragma once
#include "Road.h"

class DestroyerRoad : public Road
{
   void deleteCar();
public:
   DestroyerRoad(const int _vel, const int _length, const double semaphoreTimer, const double _frequence) : Road(_vel, _length) {}
   ~DestroyerRoad() = default;

};

#endif
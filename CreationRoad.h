#ifndef INCLUDED_CREATIONROAD_H
#define INCLUDED_CREATIONROAD_H

#pragma once
#include "Road.h"

class CreationRoad : public Road
{
   double frequence;

   void createCar();

public:
   ~CreationRoad() = default;

   CreationRoad(const int _vel, const int _length, const double semaphoreTimer, const double _frequence) : Road(_vel, _length), frequence(_frequence) {}  
   
   
};

#endif
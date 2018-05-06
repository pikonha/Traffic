#ifndef INCLUDED_CREATIONROAD_H
#define INCLUDED_CREATIONROAD_H

#pragma once
#include "Road.h"

class CreationRoad : public Road
{
   int frequence;

   Car* createCar();
public:
   ~CreationRoad() = default;

   CreationRoad(
      const int _vel,
      const int _length,
      const int semaphoreTimer,
      const int _frequence) :
      Road(_vel, _length, semaphoreTimer), frequence(_frequence)
   {}

   void getNotify(const int time) override;
};

#endif
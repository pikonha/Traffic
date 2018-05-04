#ifndef INCLUDED_CREATIONROAD_H
#define INCLUDED_CREATIONROAD_H

#pragma once
#include "Road.h"

class CreationRoad : public Road
{
   int frequence;

   void createCar();
public:
   ~CreationRoad() = default;

   CreationRoad(
      const int _vel,
      const int semaphoreTimer,
      const int _frequence) :
      Road(_vel, semaphoreTimer), frequence(_frequence)
   {}

   void getNotify(const int time) override;
};

#endif
#pragma once
#ifndef INCLUDED_CREATIONROAD_H
#define INCLUDED_CREATIONROAD_H

#include "Road.h"

class CreationRoad : public Road
{
   int frequence;

   void createCar();
public:
   ~CreationRoad() = default;

   CreationRoad(
      const std::string _name,
      const int _vel,
      const int _length,
      const int semaphoreTimer,
      const int _frequence) :
      Road(_name, _vel, _length, semaphoreTimer), frequence(_frequence)
   {}

   void getNotify(const int time) override;
};

#endif
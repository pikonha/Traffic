#ifndef INCLUDED_DESTROYERROAD_H
#define INCLUDED_DESTROYERROAD_H

#pragma once
#include "Road.h"

class DestroyerRoad : public Road
{
   void deleteCar();
   void checkFirstCar();
public:
   ~DestroyerRoad() = default;
   DestroyerRoad(
      const std::string _name,
      const int _vel,
      const int _length,
      const int semaphoreTimer) :
      Road(_name, _vel, _length, semaphoreTimer)
   {}  

   
   void getNotify(const int time) override;
};

#endif
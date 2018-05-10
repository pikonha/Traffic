#pragma once
#ifndef INCLUDED_DESTROYERROAD_H
#define INCLUDED_DESTROYERROAD_H

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
      Semaphore& _semaphore) :
      Road(_name, _vel, _length, _semaphore)
   {}  

   void moveCars() override;
};

#endif
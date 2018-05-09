#pragma once
#ifndef INCLUDED_NEUTRALROAD_H
#define INCLUDED_NEUTRALROAD_H

#include "Road.h"

class NeutralRoad : public Road
{
public:
   ~NeutralRoad() = default;
   NeutralRoad(
      const std::string _name,
      const int _vel,
      const int _length,
      const int semaphoreTimer) :
      Road(_name, _vel, _length, semaphoreTimer)
   {}  

   void getNotify(const int time) override;

};

#endif
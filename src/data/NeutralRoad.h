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
      Semaphore& _semaphore ) :
      Road(_name, _vel, _length, _semaphore)
   {}  

};

#endif
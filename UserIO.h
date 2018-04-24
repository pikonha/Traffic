#ifndef INCLUDED_USERIO_H
#define INCLUDED_USERIO_H

#pragma once
#include "Event.h"

class UserIO
{
public:
   UserIO() {}
   ~UserIO() {}

   void printEvent(const Event& event) const;

   double getExecTime() const;
   double getSemaphoreTime() const;
};

#endif
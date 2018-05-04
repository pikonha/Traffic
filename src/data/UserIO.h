#ifndef INCLUDED_USERIO_H
#define INCLUDED_USERIO_H

#pragma once
#include "Event.h"

class UserIO
{
public:
   UserIO() {}
   ~UserIO() {}

   void printEventPartition(const std::string time) const;
   void printEvent(const Event& event) const;

   int getExecTime() const;
   int getSemaphoreTime() const;
};

#endif
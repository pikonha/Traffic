#ifndef INCLUDED_CLOCK_H
#define INCLUDED_CLOCK_H

#pragma once
#include "Queue.h"
#include <string>

class Event;

class Clock
{
   Queue<Event*> events;
public:
   Clock();
   ~Clock();

   void startClock() const;
   std::string getTimeFormated() const;

};

#endif
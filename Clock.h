#ifndef INCLUDED_CLOCK_H
#define INCLUDED_CLOCK_H

#pragma once
#include <string>

class Clock
{
   time_t currentTime;

   long startTime;
   long execTime;
public:
   Clock(const long _execTime);
   ~Clock() {}

   void startClock() const;

   std::string getTimeFormated() const;

   time_t getCurrentTime() const { return currentTime; }

   void oneSec(time_t passed) const;

};

#endif
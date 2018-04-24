#ifndef INCLUDED_CLOCK_H
#define INCLUDED_CLOCK_H

#pragma once
#include <string>
#include <chrono>
#include <functional>


class Clock
{
   time_t limit;
   time_t startTime;
   time_t currentTime;

   std::function<void()> notifyAll;

public:
   Clock(const double _execTime);
   ~Clock() {}

   void startClock();

   std::string getCurrentTimeFormated();

   void oneSec(time_t passed) const;

   void connectNotify(std::function<void()> _notify) { notifyAll = _notify; }
};

#endif
#ifndef INCLUDED_CLOCK_H
#define INCLUDED_CLOCK_H

#pragma once
#include <string>
#include <functional>

class Clock
{
   time_t limit;
   time_t startTime;
   time_t currentTime;

   std::function<void(int)> notifyAll;

public:
   ~Clock() = default;
   Clock(const double _execTime);

   void startClock(const double period);

   std::string getCurrentTimeFormated();

   void oneSec() const;

   void connectNotify(std::function<void(int)> _notify) { notifyAll = _notify; }
};

#endif
#pragma once
#ifndef INCLUDED_CLOCK_H
#define INCLUDED_CLOCK_H

#include <string>
#include <functional>
#include <ctime>

class Clock
{
   std::function<void(int)> notifyAll;
public:
   ~Clock() = default;
   Clock() {}

   void startClock(const int execTime);

   std::string timeView(const time_t time);

   void oneSec(const clock_t init) const;

   void connectNotify(std::function<void(int)> _notify) { notifyAll = _notify; }
};

#endif
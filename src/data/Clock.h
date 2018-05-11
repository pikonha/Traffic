#pragma once
#ifndef INCLUDED_CLOCK_H
#define INCLUDED_CLOCK_H

#include <string>
#include <functional>
#include <ctime>

class Clock
{
   time_t execTime;

   std::function<void(int)> notifyAll;
public:
   ~Clock() = default;
   Clock(const int _execTime) : execTime(_execTime){}

   void startClock();

   std::string timeView(const time_t time);

   void oneSec(const clock_t init) const;

   void connectNotify(std::function<void(int)> _notify) { notifyAll = _notify; }
};

#endif
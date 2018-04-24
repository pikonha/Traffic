#include "stdafx.h"
#include "Clock.h"
#include <ctime>

Clock::Clock(const long _execTime)
{
   time(&currentTime);
   startTime = currentTime;

   execTime = _execTime + startTime;
}


void Clock::startClock() const
{
   while (currentTime <= execTime)
   {
      
   }
}

std::string Clock::getTimeFormated() const
{
   return "";
}

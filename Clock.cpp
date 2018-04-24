#include "stdafx.h"
#include "Clock.h"
#include <thread>
#include <iostream>

Clock::Clock(const double _execTime)
{
   time(&currentTime);
   startTime = currentTime;

   limit = startTime + _execTime;
}


void Clock::startClock()
{
   while (currentTime <= limit)
   {
      const auto passedTime = startTime + difftime(currentTime, startTime) * 240;  // cada 1s = 4min

      time(&currentTime);

      oneSec(passedTime);
   }
}

std::string Clock::getCurrentTimeFormated()
{
   char buffer[80];

   struct tm timeinfo;
   localtime_s(&timeinfo, &currentTime);

   strftime(buffer, 80, "Current date: %H:%M %d/%m/%y", &timeinfo);

   return std::string(buffer);
}

void Clock::oneSec(time_t passed) const
{
   using namespace std::literals::chrono_literals;

   std::this_thread::sleep_for(1s);
}

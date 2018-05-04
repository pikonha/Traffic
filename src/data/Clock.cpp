
#include "Clock.h"
#include <thread>

Clock::Clock(const double _execTime)
{
   time(&currentTime);
   startTime = currentTime;

   limit = startTime + _execTime;

   startClock((_execTime * 5) / 100);
}


void Clock::startClock(const double period)
{
   while (currentTime <= limit)
   {
      currentTime = startTime + difftime(currentTime, startTime) * /*period*/ 300; 

      notifyAll(currentTime);
      time(&currentTime);

      oneSec();
   }
}

std::string Clock::getCurrentTimeFormated() const
{
   char buffer[80];

   struct tm timeinfo;
   localtime_s(&timeinfo, &currentTime);

   strftime(buffer, 80, "Current date: %H:%M %d/%m/%y", &timeinfo);

   return std::string(buffer);
}

void Clock::oneSec() const
{   
   using namespace std::literals::chrono_literals;

   std::this_thread::sleep_for(1s);
}

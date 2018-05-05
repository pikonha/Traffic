
#include "Clock.h"
#include <thread>
#include <time.h>
#include <chrono>

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

std::string Clock::getCurrentTimeFormated()
{
   char buffer[80];

//    //struct tm 
//    time_t timeinfo = time(nullptr);

//    currentTime = localtime(&timeinfo);

//    strftime(buffer, 80, "Current date: %H:%M %d/%m/%y", &timeinfo);

   return std::string(buffer);
}

void Clock::oneSec() const
{   
//    using namespace std::literals::chrono_literals;

//    std::this_thread::sleep_for(1s);
}

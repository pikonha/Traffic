#include "Clock.h"
#include <thread>
#include <time.h>

#include <cstdlib> //_sleep()


void Clock::startClock(const int execTime)
{
   time_t currentTime = time(NULL);
   const long int limit = currentTime + execTime;

   while (currentTime <= limit)
   {
      const clock_t init = clock();
      notifyAll(currentTime);
      oneSec(init);

      currentTime = time(NULL);     
   }
}

std::string Clock::timeView(const time_t time)
{
   char buffer[80];

   struct tm timeinfo;

   localtime_s(&timeinfo, &time);

   strftime(buffer, 80, "%H:%M %d/%m/%y", &timeinfo);

   return std::string(buffer);
}

void Clock::oneSec(const clock_t init) const
{   
   // ReSharper disable CppDeprecatedEntity
   _sleep(1000 - (clock() - init));
   // ReSharper restore CppDeprecatedEntity

    //using namespace std::literals::chrono_literals;

    //std::this_thread::sleep_for(1s);
}

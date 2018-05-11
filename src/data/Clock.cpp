#include "Clock.h"
#include <thread>
#include <time.h>

#include <cstdlib> //_sleep()


void Clock::startClock()
{
   time_t currentTime = time(NULL);
   const time_t limit = currentTime + execTime;

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

}

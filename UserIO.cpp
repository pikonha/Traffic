#include "stdafx.h"
#include "UserIO.h"
#include <iostream>

void UserIO::printEvent(const Event& event) const
{
   std::cout << "Event ocurred:" << event.getTime() << " - " << event.getDescriptiom() << std::endl;
}

double UserIO::getExecTime() const
{
   std::cout << "Insert the application time limit: " << std::endl;
  
   std::string time;
   std::cin >> time;

   return stod(time);
}

double UserIO::getSemaphoreTime() const
{
   std::cout << "Insert the semaphore's changing time: " << std::endl;

   std::string time;
   std::cin >> time;

   return stod(time);
}

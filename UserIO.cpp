#include "stdafx.h"
#include "UserIO.h"
#include <iostream>

void UserIO::printEventPartition(const std::string time) const
{
   std::cout << "\n-----------------------------" << time << "-----------------------------\n" << std::endl;
}

void UserIO::printEvent(const Event& event) const
{
   std::cout << "Event ocurred:" << event.description << std::endl;
}

int UserIO::getExecTime() const
{
   std::cout << "Insert the application time limit: " << std::endl;
  
   std::string time;
   std::cin >> time;

   return stoi(time);
}

int UserIO::getSemaphoreTime() const
{
   std::cout << "Insert the semaphore's changing time: " << std::endl;

   std::string time;
   std::cin >> time;

   return stoi(time);
}

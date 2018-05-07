#include "UserIO.h"
#include <iostream>

void UserIO::printEventPartition(const std::string time)
{
   system("cls");
   std::cout << "\n-----------------------------" << time << "-----------------------------\n";
}

void UserIO::printLogs(const std::string name, const Logger log) const
{
   std::cout << "-------------------------------------------------" << std::endl;
   std::cout << "Road " << name << ":" << std::endl;
   std::cout << "Entry: " << log.getEntry() << std::endl;
   std::cout << "Left: " << log.getLeft() << std::endl;
   std::cout << "Created: " << log.getCreated() << std::endl;
   std::cout << "Deleted: " << log.getDeleted() << std::endl;
   std::cout << "Blocked: " << log.getBlocked() << std::endl;
   std::cout << "-------------------------------------------------" << std::endl;
}

void UserIO::printTotalLogs() const
{
   std::cout << "\n-----------------------------" << "TOTAL" << "-----------------------------\n";
   std::cout << "Entry: " << entry << std::endl;
   std::cout << "Left: " << left << std::endl;
   std::cout << "Created: " << created << std::endl;
   std::cout << "Deleted: " << deleted << std::endl;
   std::cout << "Blocked: " << blocked << std::endl;
}

void UserIO::addLog(const Logger log)
{  
   entry += log.getEntry();  
   left += log.getLeft();
   created += log.getCreated();
   deleted += log.getDeleted();
   blocked += log.getBlocked();
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

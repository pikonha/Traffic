#include "UserIO.h"

void UserIO::buildTable()
{
   table.setAlignment(2, TextTable::Alignment::LEFT);

   table.add("");
   table.add("Entry");
   table.add("Left");
   table.add("Created");
   table.add("Deleted");
   table.add("Blocked");
   table.endOfRow();
}

void UserIO::printEventPartition(const std::string time)
{
   system("cls");
   std::cout << "---------------" << time << "---------------\n";
   buildTable();
}

void UserIO::addLogToTable(const std::string name, const Logger log)
{
   table.add(name);
   table.add(std::to_string(log.getEntry()));
   table.add(std::to_string(log.getLeft()));
   table.add(std::to_string(log.getCreated()));
   table.add(std::to_string(log.getDeleted()));
   table.add(std::to_string(log.getBlocked()));
   table.endOfRow();
}

void UserIO::printTotalLogs()
{
   table.add("TOTAL");
   table.add(std::to_string(entry));
   table.add(std::to_string(left));
   table.add(std::to_string(created));
   table.add(std::to_string(deleted));
   table.add(std::to_string(blocked));   
   table.endOfRow();

   std::cout << table;

   table = TextTable();

   entry = left = created = deleted = blocked = 0;
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

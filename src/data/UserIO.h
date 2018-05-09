#pragma once
#ifndef INCLUDED_USERIO_H
#define INCLUDED_USERIO_H

#include <string>
#include "Logger.h"
#include "TextTable.h"

class UserIO
{
   int entry;
   int left;
   int created;
   int deleted;
   int blocked;

   TextTable table;
public:
   UserIO() : entry(0), left(0), created(0), deleted(0), blocked(0) {}
   ~UserIO() {}

   void buildTable();

   void printEventPartition(const std::string time);
   void addLogToTable(const std::string name, const Logger log);
   void printTotalLogs();
   void addLog(const Logger log);

   int getExecTime() const;
   int getSemaphoreTime() const;
};

#endif
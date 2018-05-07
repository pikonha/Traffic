#ifndef INCLUDED_USERIO_H
#define INCLUDED_USERIO_H

#pragma once
#include <string>
#include "Logger.h"

class UserIO
{
   int entry;
   int left;
   int created;
   int deleted;
   int blocked;
public:
   UserIO() : entry(0), left(0), created(0), deleted(0), blocked(0) {}
   ~UserIO() {}

   void printEventPartition(const std::string time);
   void printLogs(const std::string name, const Logger log) const;
   void printTotalLogs() const;
   void addLog(const Logger log);

   int getExecTime() const;
   int getSemaphoreTime() const;
};

#endif
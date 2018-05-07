#pragma once

#ifndef INCLUDED_LOGGER_H
#define INCLUDED_LOGGER_H

enum LOG
{
   CAR_ENTRY,
   CAR_LEFT,
   CAR_CREATED,
   CAR_DELETED,
   CAR_BLOCKED
};

class Logger
{  
   int carsEntry;
   int carsLeft;
   int carsCreated;
   int carsDeleted;
   int carsBlocked;

public:
   ~Logger() = default;
   Logger() : carsEntry(0), carsLeft(0), carsCreated(0), carsDeleted(0), carsBlocked(0) {}

   inline void addLog(const LOG log)
   {
      switch (log)
      {
      case CAR_ENTRY:         ++carsEntry;      break;
      case CAR_LEFT:          ++carsLeft;       break;
      case CAR_CREATED:       ++carsCreated;    break;
      case CAR_DELETED:       ++carsDeleted;    break;
      case CAR_BLOCKED:       ++carsBlocked;    break;
      }
   }

   int getEntry() const { return carsEntry; }
   int getLeft() const { return carsLeft; }
   int getCreated() const { return carsCreated; }
   int getDeleted() const { return carsDeleted; }
   int getBlocked() const { return carsBlocked; }

};


#endif
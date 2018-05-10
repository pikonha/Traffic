#pragma once
#ifndef INCLUDED_SEMAPHORERINGLIST_H
#define INCLUDED_SEMAPHORERINGLIST_H

#include "RingList.h"
#include "Semaphore.h"

class SemaphoreRingList : public RingList<Semaphore*>
{
   int timeOpen;
public:  
   ~SemaphoreRingList() = default;
   SemaphoreRingList() : RingList<Semaphore*>(), timeOpen(0) {}

   void resetTimeOpen() { timeOpen = 0; }
   void checkState();
};

inline void SemaphoreRingList::checkState()
{
   auto tmp = head;

   while (tmp->getData()->getState() != GREEN) 
      tmp = tmp->getNext();    

   if (timeOpen == tmp->getData()->getTimer())
   {
      tmp->getData()->changeState();
      resetTimeOpen();
      tmp->getNext()->getData()->changeState();
   }
   else
      timeOpen++;
}



#endif
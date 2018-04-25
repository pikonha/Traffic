#include "stdafx.h"
#include "NeutralRoad.h"

void NeutralRoad::getNotify(const int time)
{   
   if (semaphore->getTimer() % time == 0)
      semaphore->changeState();   

   
}

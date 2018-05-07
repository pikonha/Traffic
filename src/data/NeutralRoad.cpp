
#include "NeutralRoad.h"

void NeutralRoad::getNotify(const int time)
{   
   if (semaphore->getTimer() <= time )
      semaphore->changeState();   

   if (semaphore->isOpen())
      moveCars();
}

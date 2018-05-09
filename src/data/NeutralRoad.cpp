
#include "NeutralRoad.h"

void NeutralRoad::getNotify(const int time)
{   
   if (time % semaphore->getTimer() == 0)
      semaphore->changeState();   

   moveCars();
}

#include "stdafx.h"
#include "Highway.h"


Highway::Highway(const double vel1, const double length1, const double vel2, const double length2, const double semaphoreTimer) : semaphore(new Semaphore(semaphoreTimer))
{
   road1 = new Road(vel1, length1);
   road2 = new Road(vel2, length2);
}


Highway::~Highway()
{
   delete road1;
   delete road2;
   delete semaphore;
}

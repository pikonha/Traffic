#include "stdafx.h"
#include "Highway.h"


Highway::Highway(const double semaphoreTimer) : semaphore(new Semaphore(semaphoreTimer))
{
}


Highway::~Highway()
{
   delete semaphore;
}

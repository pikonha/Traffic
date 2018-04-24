#include "stdafx.h"
#include "Road.h"

Road::Road(const int _vel, const int _length, const double semaphoreTimer) :
   velocity(_vel), length(_length), semaphore(new Semaphore(semaphoreTimer))
{}

Road::~Road()
{
   delete semaphore;
}

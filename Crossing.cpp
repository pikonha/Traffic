#include "stdafx.h"
#include "Crossing.h"


Crossing::Crossing(const double semaphoreTimer)
{
   //highway1 = new Highway(semaphoreTimer);
   //highway2 = new Highway(semaphoreTimer);
   //highway3 = new Highway(semaphoreTimer);
   //highway4 = new Highway(semaphoreTimer);
}


Crossing::~Crossing()
{
   delete highway1;
   delete highway2;
   delete highway3;
   delete highway4;
}

void Crossing::notify() const
{

}

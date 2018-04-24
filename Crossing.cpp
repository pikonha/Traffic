#include "stdafx.h"
#include "Crossing.h"


Crossing::Crossing(const double semaphoreTimer) : highway1(new Highway(semaphoreTimer)), highway2(new Highway(semaphoreTimer)) {}


Crossing::~Crossing()
{
}

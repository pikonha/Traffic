#include "stdafx.h"
#include "Car.h"
#include <random>

Car::Car(const int _speed) : speed(_speed)
{
   length = rand() % 7 + 2;
   walked = 0;
}

void Car::move()
{
   walked += (speed / 3.6) * 300;
}

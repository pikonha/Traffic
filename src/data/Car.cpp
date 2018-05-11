
#include "Car.h"
#include <random>

Car::Car(const int _speed) : speed(_speed)
{
   option = rand() % 10;
   length = rand() % 7 + 2;
   walked = 0;
}

void Car::move()
{
   walked += (speed / 3.6);
}

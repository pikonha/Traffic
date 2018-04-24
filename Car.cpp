#include "stdafx.h"
#include "Car.h"
#include <random>

Car::Car()
{
   length = rand() % 7 + 2;
}


Car::~Car()
{
}

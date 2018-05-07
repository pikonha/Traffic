#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#pragma once
#include "Clock.h"
#include "UserIO.h"
#include "Road.h"
#include "Lista.h"

class App
{
   Clock* clock;
   UserIO* userIO;

   Lista<Road*> roads;

   void createRoads(const int timer);
public:
   App();
   ~App();

   void notifyAll(int time);
};

#endif
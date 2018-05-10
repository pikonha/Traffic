#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#include "Clock.h"
#include "UserIO.h"
#include "Road.h"
#include "Lista.h"
#include "SempahoreRingList.h"

class App
{
   Clock* clock;
   UserIO* userIO;

   Lista<Road*> roads;
   SemaphoreRingList semaphoreS1;
   SemaphoreRingList semaphoreS2;

   void createRoads();
   void createSemaphores(const int timer);
   
   void checkSemaphoresTime();
public:
   App();
   ~App();

   virtual void notifyAll(int time);

   void startApplication() const;
};

#endif
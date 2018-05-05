#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#pragma once
#include "Event.h"
#include "Clock.h"
#include "UserIO.h"
#include "Road.h"
#include "Lista.h"

class App
{
   Clock* clock;
   UserIO* userIO;

   Lista<Road*> roads;
   Lista<Event*> events;

   void createRoads(const int timer);
   void connectRoadEvent(Road* road);
public:
   App();
   ~App();

   void notifyAll(int time);

   void addEvent(std::string description);
};

#endif
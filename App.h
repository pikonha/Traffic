#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#pragma once
#include "Event.h"
#include "Clock.h"
#include "UserIO.h"
#include "Road.h"

class App
{
   Clock* clock;
   UserIO* userIO;

   List<Road*>* roads;
   List<Event*>* events;

   void createRoads(const int timer);
public:
   App();
   ~App();

   void notifyAll(int time);

   void addEvent(const std::string description);
};

#endif
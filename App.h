#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#pragma once
#include "Event.h"
#include <queue>
#include <functional>
#include "Clock.h"
#include "UserIO.h"
#include <vector>
#include "Road.h"

class App
{
   std::queue<Event*> events;

   Clock* clock;
   UserIO* userIO;

   std::vector<Road*> roads;

   void createRoads(const int timer);
public:
   App();
   ~App();

   void notifyAll(int time);

   void addEvent(const std::string description);
};

#endif
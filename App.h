#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#pragma once
#include "Event.h"
#include <queue>
#include <functional>
#include "Clock.h"
#include "UserIO.h"

class App
{
   std::queue<Event*> events;

   Clock* clock;
   UserIO* userIO;


public:
   App();
   ~App();

   void notifyAll();

   void addEvent(const std::string description);
};

#endif
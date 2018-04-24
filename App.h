#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#pragma once
#include "Event.h"
#include <queue>

class App
{
   std::queue<Event*> events;
public:
   App();
   ~App();

   void notifyAll();
};

#endif
#include "stdafx.h"
#include "App.h"


App::App() : userIO(new UserIO())
{
   clock = new Clock(userIO->getExecTime());
}


App::~App()
{
   delete clock;
   delete userIO;
}

void App::notifyAll()
{
}

void App::addEvent(const std::string description)
{
   events.push(new Event(clock->getCurrentTime(), description));
}

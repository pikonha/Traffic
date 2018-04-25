#ifndef INCLUDED_EVENT_H
#define INCLUDED_EVENT_H

#pragma once
#include <string>

class Event
{
public:
   Event(const std::string _time, const std::string _description);
   ~Event();

   const std::string time;
   const std::string description;
};

#endif
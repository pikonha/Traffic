#ifndef INCLUDED_EVENT_H
#define INCLUDED_EVENT_H

#pragma once
#include <string>


class Event
{
   int time;
   std::string description;

public:
   Event(const int _time, const std::string _description);
   ~Event();
};

#endif
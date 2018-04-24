#ifndef INCLUDED_EVENT_H
#define INCLUDED_EVENT_H

#pragma once
#include <string>


class Event
{
   time_t time;
   std::string description;

public:
   Event(const time_t _time, const std::string _description);
   ~Event();

   time_t getTime() const { return time; }
   std::string getDescriptiom() const { return description; }
};

#endif
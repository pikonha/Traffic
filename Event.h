#ifndef INCLUDED_EVENT_H
#define INCLUDED_EVENT_H

#pragma once
#include <string>


class Event
{
   std::string time;
   std::string description;

public:
   Event(const std::string _time, const std::string _description);
   ~Event();

   std::string getTime() const { return time; }
   std::string getDescriptiom() const { return description; }
};

#endif
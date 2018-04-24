#ifndef INCLUDED_SEMAPHORE_H
#define INCLUDED_SEMAPHORE_H

#pragma once

enum State
{
   OPEN,
   CLOSED
};

class Semaphore
{
   State state;
   double timer;

public:
   ~Semaphore() {}
   Semaphore(const double _timer) : state(CLOSED), timer(_timer) {}

   void changeState(const State _state) { state = _state; }
   
};

#endif
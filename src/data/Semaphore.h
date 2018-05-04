#ifndef INCLUDED_SEMAPHORE_H
#define INCLUDED_SEMAPHORE_H

#pragma once

enum State
{
   GREEN, RED
};

class Semaphore
{
   State state;
   int timer;

public:
   ~Semaphore() {}
   Semaphore(const int _timer) : state(RED), timer(_timer) {}

   int getTimer() const { return timer; }
   void changeState() { state == RED ? state = GREEN : state = RED; }
   
};

#endif
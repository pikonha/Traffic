#ifndef INCLUDED_CARS_H
#define INCLUDED_CARS_H

#pragma once

class Car;

class Cars
{

   Car* contents;
public:
   Cars();
   ~Cars();

   void enqueue(Car* data);
   Car* dequeue();

   Car* back();
   void clear();

   bool empty();
   bool full();
};

#endif
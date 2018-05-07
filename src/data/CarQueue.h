#pragma once
#ifndef INCLUDED_CARQUEUE_H
#define INCLUDED_CARQUEUE_H

#include "LinkedQueue.h"
#include "Car.h"
#include <stdexcept>

class CarQueue : public LinkedQueue<Car>
{
   int capacity;

public:
   ~CarQueue() = default;
   CarQueue(const int _capacity) : capacity(_capacity) {}

   Car dequeue() override;
   void enqueue(const Car& car) override;

   bool itFits(const Car* car) const { return capacity >= car->getLength(); }
   int getCapacity() const { return capacity; }

   void moveCars() const;
};

///////////////////////////////////////////////////////////////////// 

inline void CarQueue::enqueue(const Car& car)
{
   if (!itFits(&car))
      throw std::overflow_error("Full queue");

   if (empty())
      tail = head = new Node(car);

   else
      tail = new Node(car, tail);

   capacity -= car.getLength();
   size_++;
}

inline void CarQueue::moveCars() const
{
   auto temp = head;
   for (int i = 0; i < size_; i++)
   {
      temp->data().move();
      temp = temp->next();
   }
}

inline Car CarQueue::dequeue()
{
   if (empty())
      throw std::out_of_range("LIST IS EMPTY!");

   auto temp = head;
   while (temp->next() != tail)
      temp = temp->next();

   auto aux = temp->next()->data();
   temp->next(nullptr);
   tail = temp;

   size_--;
   capacity += temp->data().getLength();

   return aux;
}


#endif
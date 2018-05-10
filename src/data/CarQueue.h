#pragma once
#ifndef INCLUDED_CARQUEUE_H
#define INCLUDED_CARQUEUE_H

#include "LinkedQueue.h"
#include "Car.h"
#include <stdexcept>

class CarQueue : public LinkedQueue<Car*>
{
   int capacity;

public:
   ~CarQueue() = default;
   CarQueue(const int _capacity) : LinkedQueue<Car*>(), capacity(_capacity) {}

   Car* dequeue() override;
   void enqueue(Car* const& data) override;

   bool itFits(const Car* car) const { return capacity >= car->getLength(); }
   int getCapacity() const { return capacity; }

   void moveCars();
};

///////////////////////////////////////////////////////////////////// 
inline void CarQueue::enqueue(Car* const& car)
{
   if (!itFits(car))
      throw std::overflow_error("Full queue");

   if (empty())
      tail = head = new Node(car);

   else
      tail = new Node(car, tail);

   capacity -= car->getLength();
   size_++;
}


inline void CarQueue::moveCars()
{
   auto temp = tail;

   for (int i = 0; i < size_; i++)
   {
      temp->data()->move();
      temp = temp->next();
   }   
}

inline Car* CarQueue::dequeue()
{
   if (empty())
      throw std::out_of_range("LIST IS EMPTY!");

   if (size_ == 1)
   {
      const auto temp = head->data();
      head = tail = nullptr;
      size_--;
      return temp;
   }

   auto temp = tail;
   while (temp->next() != head)
      temp = temp->next();

   auto aux = temp->next()->data();
   temp->next(nullptr);
   head = temp;

   size_--;
   capacity += aux->getLength();

   return aux;
}


#endif
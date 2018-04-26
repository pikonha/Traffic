#ifndef INCLUDED_QUEUE_H
#define INCLUDED_QUEUE_H

#pragma once

template<typename T>
class Queue
{
   T * contents;

   int size;
   int capacity;
public:
   ~Queue();
   Queue(int _capacity);

   T dequeue();
   void enqueue(const T& data);

   T& front();

   void clear();
      
   int getSize() const { return size; }
   int getCapacity() const { return capacity; }

   bool full() const;
   bool empty() const;  
};

#endif

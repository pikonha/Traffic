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
   Queue();

   ~Queue();
   Queue(std::size_t max);

   T dequeue();
   void enqueue(const T& data);

   T& back();

   void clear();
      
   std::size_t getSize() const { return size; }
   std::size_t getCapacity() const { return capacity; }

   bool full() const;
   bool empty() const;  
};



#endif

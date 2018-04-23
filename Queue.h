#ifndef INCLUDED_QUEUE_H
#define INCLUDED_QUEUE_H

#pragma once

template<typename T> class Queue
{
   T * contents;

   int size;
   int maxSize;

public:
   ~Queue();
   Queue(const int max);

   T dequeue();
   void enqueue(const T& data);

   T& back();

   void clear();

   int getSize() const { return size; }
   int getMaxSize() const { return maxSize; }

   bool empty();
   bool full();

};


#endif;

// Copyright 2017 <Diogo Junior de Souza>

#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include <cstdint>   // std::size_t
#include <stdexcept> // C++ exceptions
#include "LinkedList.h"

template <typename T>
class LinkedQueue
{
    public:
      LinkedQueue() : linkedList_{}
      {
      }

      ~LinkedQueue() {}

      void clear()
      {
            linkedList_.clear();
      }

      void enqueue(const T &data)
      {
            linkedList_.push_back(data);
      }

      T dequeue()
      {
            return linkedList_.pop_front();
      }

      T &front() const
      {
            return linkedList_.at(0);
      }

      T &back() const
      {
            return linkedList_.at(size() - 1);
      }

      bool empty() const
      {
            return linkedList_.empty();
      }

      std::size_t size() const
      {
            return linkedList_.size();
      }

    private:
      LinkedList<T> linkedList_;
};

#endif

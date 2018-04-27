#include "stdafx.h"
#include "Queue.h"


template <typename T>
Queue<T>::~Queue()
{
   clear();
}

template <typename T>
Queue<T>::Queue(const int _capacity)
{
   size = 0;
   capacity = _capacity;
   contents = new T[_capacity];
}

/* Throws std::underflow_error */
template <typename T>
T Queue<T>::dequeue()
{
   if (empty())
      throw std::underflow_erro("Empty queue.")

   auto temp = contents[0];
   for (int i = 0; i < size; i++)
      contents[i] = contents[i + 1];
   size--;
   return temp;
 
}

/* Throws std::overflow_error */
template <typename T>
void Queue<T>::enqueue(const T& data)
{
   if (full())
      throw std::overflow_error("Full queue.");
   
   contents[size++] = data;
}

template <typename T>
T& Queue<T>::back()
{
   if (empty())
      throw std::out_of_range("Lista vazia");
   return contents[size_ - 1];
}

template <typename T>
void Queue<T>::clear()
{
   while (size)
      delete dequeue();
}

template <typename T>
bool Queue<T>::full() const
{
   return size == capacity;
}

template <typename T>
bool Queue<T>::empty() const
{
   return size == 0;
}
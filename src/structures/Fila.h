#pragma once
#ifndef INCLUDED_FILA_H
#define INCLUDED_FILA_H

#include <stdexcept>

template<class T>
class Fila
{
   T * contents;

   int size;
   int capacity;
public:
   ~Fila();
   Fila(const int _capacity);

   T dequeue();
   void enqueue(const T& data);

   T& back();

   void clear();
      
   int getSize() const { return size; }
   int getCapacity() const { return capacity; }

   bool full() const;
   bool empty() const;  
};

template <class T>
Fila<T>::~Fila()
{
   clear();
}

template <class T>
Fila<T>::Fila(const int _capacity)
{
   size = 0;
   capacity = _capacity;
   contents = new T[_capacity];
}

/* Throws std::underflow_error */
template <class T>
T Fila<T>::dequeue()
{
   if (empty())
      throw std::underflow_error("Empty queue.");

   auto temp = contents[0];
   for (int i = 0; i < size; i++)
      contents[i] = contents[i + 1];
   size--;
   return temp;

}

/* Throws std::overflow_error */
template <class T>
void Fila<T>::enqueue(const T& data)
{
   if (full())
      throw std::overflow_error("Full queue.");

   contents[size++] = data;
}

template <class T>
T& Fila<T>::back()
{
   if (empty())
      throw std::out_of_range("Lista vazia");
   return contents[size - 1];
}

template <class T>
void Fila<T>::clear()
{
   while (size)
      delete dequeue();
}

template <class T>
bool Fila<T>::full() const
{
   return size == capacity;
}

template <class T>
bool Fila<T>::empty() const
{
   return size == 0;
}
#endif

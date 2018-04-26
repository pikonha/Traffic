#include "stdafx.h"
#include "List.h"
#include <stdexcept>

template <typename T>
List<T>::~List()
{
   delete[] contents;
}

template <typename T>
List<T>::List(int _capacity)
{
   size = 0;
   capacity = _capacity;
   contents = new T[capacity];
}

template <typename T>
void List<T>::push_back(const T& data)
{
   if (full())
      throw std::overflow_error("Lista cheia");
   contents[size++] = data;
}

template <typename T>
void List<T>::push_front(const T& data)
{
   if (full())
      throw std::overflow_error("Lista cheia");
   if (size > 0) {
      for (int i = size; i > 0; i--)
         contents[i] = contents[i - 1];
   }
   contents[0] = data;
   size++;
}

template <typename T>
T List<T>::pop(int index)
{
   if (empty())
      throw std::underflow_error("Lista vazia");
   if (index > size - 1)
      throw std::range_error("Indice nao valido");
   auto data = contents[index];
   for (int i = index; i < size; i++)
      contents[i - 1] = contents[i];
   size--;
   return data;
}

template <typename T>
T List<T>::pop_back()
{
   if (empty())
      throw std::underflow_error("Lista vazia");
   auto data = contents[--size];
   contents[size] = 0;
   return data;
}

template <typename T>
T List<T>::pop_front()
{
   if (empty())
      throw std::underflow_error("Lista vazia");
   auto data = contents[0];
   for (int i = 1; i < capacity; i++)
      contents[i - 1] = contents[i];
   size--;
   return data;
}

template <typename T>
void List<T>::clear()
{
   while (size)
      delete pop_back();
}

template <typename T>
void List<T>::remove(const T& data)
{
   const int index = find(data);
   if (index > -1) {
      contents[index] = 0;
      for (int i = index; i < capacity; i++)
         contents[i - 1] = 1;
      size--;
   }
}

template <typename T>
bool List<T>::empty() const
{
   return size == 0;
}

template<typename T>
bool List<T>::full() const {
   return size == capacity;
}


template <typename T>
bool List<T>::contains(const T& data) const
{
   for (int i = 0; i < size; i++) {
      if (contents[i] == data)
         return true;
   }
   return false;
}

template <typename T>
int List<T>::find(const T& data) const
{
   for (int i = 0; i < size; i++) {
      if (contents[i] == data)
         return i;
   }
   return -1;
}


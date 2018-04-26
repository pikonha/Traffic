#ifndef INCLUDED_LIST_H
#define INCLUDED_LIST_H

#pragma once

template<typename T>
class List
{
   T * contents;

   int size;
   int capacity;

public:
   ~List();
   List(int _capacity);

   void push_back(const T& data);
   void push_front(const T& data);

   T pop(int index);
   T pop_back();
   T pop_front();

   void clear();
   void remove(const T& data);

   bool empty() const;
   bool full() const;
   bool contains(const T& data) const;

   int find(const T& data) const;

   int getSize() const { return size; }
   int getCapacity() const { return capacity; }

   T& operator[](int index) const { return contents[index]; }
};


#endif

#pragma once
#ifndef INCLUDED_RINGLIST_H
#define INCLUDED_RINGLIST_H

template <typename T>
class RingList
{
protected:
   class Node
   {
      T data;
      Node* prev;
      Node* next;
   public:
      Node(const T& _data, Node* _prev=nullptr, Node* _next=nullptr) : data(_data), prev(_prev), next(_next) { 
      }

      T& getData() {
         return data;
      }
   
      Node* getPrev() {
         return prev;
      }

      void setPrev(Node* node) {
         prev = node;
      }

      Node* getNext() {
         return next;
      }

      void setNext(Node* node) {
         next = node;
      } 
   };

   Node* head;
   std::size_t size;

public:
   virtual ~RingList();
   RingList() : head(nullptr), size(0){}

   void push(const T& data);

   void clear();

   T& at(int index);
   T& operator[](const int index);

   bool empty() const;
};

template<typename T>
RingList<T>::~RingList()
{
   clear();
}


template<typename T>
void RingList<T>::push(const T& data)
{
   if (empty())
      head = new Node(data);
   else if (size == 1) {
      auto node = new Node(data, head, head);
      head->setNext(node);
      head->setPrev(node);
   } else
   {
      auto node = new Node(data, head->getPrev(), head);
      head->getPrev()->setNext(node);
      head->setPrev(node);
   }
   size++;
}

template<typename T>
void RingList<T>::clear()
{
   if (!empty())
   {
   }
}


template<typename T>
T& RingList<T>::at(int index)
{
   if (index >= size || index < 0)
      std::out_of_range("Index error");

   auto current = head;

   for (int i = 0; i < index; i++)
      current = current->getNext();

   return current->getData();
}

template <typename T>
T& RingList<T>::operator[](const int index)
{
   return at(index);
}


template<typename T>
 bool RingList<T>::empty() const
{
   return size == 0;
}

#endif // INCLUDED_RINGBUFFER_H

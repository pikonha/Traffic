#pragma once
#ifndef INCLUDED_LINKEDQUEUE_H
#define INCLUDED_LINKEDQUEUE_H

#include <stdexcept>

template<typename T>
class LinkedQueue
{
protected:
   class Node { 
   public:
      Node(const T& data, Node* next=nullptr) :
         data_( data ),
         next_( next )
      {}

      T data() {  
         return data_;
      }

      Node* next() {  
         return next_;
      }

      void next(Node* node) {  
         next_ = node;
      }

   private:
      T data_;
      Node* next_;
   };

   Node* head;
   Node* tail;
   std::size_t size_;

public:
   virtual ~LinkedQueue();
   LinkedQueue();

   virtual void clear();
   virtual void enqueue(const T& data);

   virtual T dequeue();
   T front() const;
   T back() const;

   bool empty() const;

   std::size_t size() const;
};

template<typename T>
LinkedQueue<T>::~LinkedQueue()
{
   clear();
}

template<typename T>
LinkedQueue<T>::LinkedQueue()
{
   head= tail= nullptr;
   size_= 0;
}

template<typename T>
void LinkedQueue<T>::clear()
{
   while(size_)
      dequeue();
}

template<typename T>
void LinkedQueue<T>::enqueue(const T & data)
{
   if (empty()) 
      tail = head= new Node(data);   
   else 
      tail = new Node(data,tail);
   size_++;
}

template<typename T>
T LinkedQueue<T>::dequeue()
{
   if (empty())
      throw std::out_of_range("LIST IS EMPTY!");

   auto aux = head->data();
   if (size_ == 1)
      head = tail = nullptr;
   else {
      auto temp = tail;
      while (temp->next() != head)
         temp = temp->next();

      aux = temp->next()->data();
      temp->next(nullptr);
   }
   size_--;

   return aux;
}

template<typename T>
T LinkedQueue<T>::front() const
{
   if (empty())
      throw std::out_of_range("LIST IS EMPTY!");
   return head->data();
}

template<typename T>
 T LinkedQueue<T>::back() const
{
   if (empty())
      throw std::out_of_range("LIST IS EMPTY!");
   return tail->data();
}

template<typename T>
 bool LinkedQueue<T>::empty() const
{
   return size_ == 0;
}

template<typename T>
std::size_t LinkedQueue<T>::size() const
{
   return size_;
}


#endif // !INCLUDED_LINKEDQUEUE_H

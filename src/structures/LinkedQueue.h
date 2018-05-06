#pragma once
#ifndef INCLUDED_LINKEDQUEUE_H
#define INCLUDED_LINKEDQUEUE_H

template<typename T>
class LinkedQueue
{
   class Node {  // Elemento
   public:
      explicit Node(const T& data) : data_{ data }
      {}

      Node(const T& data, Node* next) :
         data_{ data },
         next_{ next }
      {}

      T& data() {  
         return data_;
      }

      const T& data() const {  
         return data_;
      }

      Node* next() {  
         return next_;
      }

      const Node* next() const {  
         return next_;
      }

      void next(Node* node) {  
         next_ = node;
      }

   private:
      T data_;
      Node* next_{ nullptr };
   };

   Node* head;
   Node* tail;
   std::size_t size_;

public:
   ~LinkedQueue();
   LinkedQueue();
   
   void clear();
   void enqueue(const T& data);

   T dequeue();
   T& front() const;
   T& back() const;

   bool empty() const;

   std::size_t size() const;

   void forEach(std::function<void(T)> func);
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
   if (empty()) {
      head= new Node(data);
      tail= head;
   } 
   else {
      auto new_node= new Node(data);
      tail->next(new_node);
      tail= new_node;
   }
   size_++;
}

template<typename T>
T LinkedQueue<T>::dequeue()
{
   if (empty())
      throw std::out_of_range("LIST IS EMPTY!");

   if (size_ == 1) {
      T temp= head->data();
      head= nullptr;
      tail= nullptr;
      size_--;
      return temp;
   }
   Node* current= head;
   T temp= current->data();
   head= current->next();
   delete current;
   size_--;
   return temp;
}

template<typename T>
T &LinkedQueue<T>::front() const
{
   if (empty())
      throw std::out_of_range("LIST IS EMPTY!");
   return head->data();
}

template<typename T>
 T &LinkedQueue<T>::back() const
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

template <typename T>
void LinkedQueue<T>::forEach(std::function<void(T)> func)
{
   auto temp = head;

   for (int i = 0; i < size_; i++)
   {
      func(temp);
      temp = temp->next_;
   }
}

#endif // !INCLUDED_LINKEDQUEUE_H

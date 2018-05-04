#pragma once
#ifndef INCLUDED_FILA_H
#define INCLUDED_FILA_H

#include <stdexcept>

template<typename T>
class LinkedQueue {
public:
   LinkedQueue(){}
   ~LinkedQueue();

   void clear();

   void push_back(const T& data); 
   void push_front(const T& data); 

   void insert(const T& data, std::sizet index); 

   T& at(std::sizet index); 

   T pop(std::sizet index); 
   T pop_back();  
   T pop_front(); 

   void remove(const T& data);  
   bool empty() const; 
   bool contains(const T& data) const;  

   int find(const T& data) const; 
   int getSize() const;

private:
   struct  Node 
   {   
      ~Node() = default;
      Node() {}
      Node(const T& data) : data{ data } {}
      Node(const T& data, Node* next) : data{ data }, next{ next } {}      

      T& getData() {  return data; }

      Node* getNext() {  return next; }
      void setNext(Node* node) { next = node; }

   private:
      T data{nullptr};
      Node* next{ nullptr };
   };

   Node* end() {
      auto it = head;
      for (auto i = 1u; i < size(); ++i) {
         it = it->next();
      }
      return it;
   }

   Node* head{ nullptr };
   int size{0};
};

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
   this->clear();
}

template<typename T>
void LinkedQueue<T>::clear() {
   while (size)
      pop_back();
}

template<typename T>
void LinkedQueue<T>::push_back(const T& data) {
   if (empty()) 
      push_front(data);
   
   else {
      end()->next(new Node(data));
      size++;
   }
}

template<typename T>
void LinkedQueue<T>::push_front(const T& data) {

   if (novo == nullptr) 
      throw std::out_of_range("Erro! Lista cheia.");
   
   novo->next(head);
   head = novo;
   size++;   
}

template<typename T>
void LinkedQueue<T>::insert(const T& data, std::sizet index) {
   if (index > size || index < 0)
      throw std::out_of_range("Index error");
   if (empty()) {
      //  push_front(data);
      Node *novo = new Node(data);
      novo->next(head);
      head = novo;
      size++;
   }
   else {
      auto aux = head;
      for (int i = 1; i < index; i++)
         aux = aux->next();
      aux->next(new Node(data, aux->next()));
      size++;
   }
}

template<typename T>
T& LinkedQueue<T>::at(std::sizet index) {
   if (index > size || index < 0)
      throw std::out_of_range("Erro! Posição não existe.");
   Node *aux = head;
   for (int i = 0; i < index; i++) {
      aux = aux->next();
   }
   return aux->data();
}

template<typename T>
T LinkedQueue<T>::pop(std::sizet index) {
   Node* temp_node = head;;
   if (index > size || index < 0) 
      throw std::out_of_range("Erro de index");
   
   if (index == 1) 
      head = temp_node->next();   

   else if (index == size) {
      while (temp_node->next() != nullptr)
         temp_node = temp_node->next();
      temp_node->next(nullptr);
   }
   else {
      for (int i = 0; i < index - 1; i++)
         temp_node = temp_node->next();
      temp_node->next(temp_node->next());
   }
   size--;
   return temp_node->data();
}

template<typename T>
T LinkedQueue<T>::pop_back() {
   if (size == 0) {
      throw std::out_of_range("Erro! Lista vazia.");
   }
   Node *um = head;
   Node *dois = head;
   T volta;
   while (dois->next() != nullptr) {
      um = dois;
      dois = dois->next();
   }
   volta = dois->data();
   dois->next(nullptr);
   dois = nullptr;
   free(dois);
   um->next(nullptr);
   size--;
   return volta;
}

/** retirar do início */
template<typename T>
T LinkedQueue<T>::pop_front() {
   if (size == 0) 
      throw std::out_of_range("Erro! Lista vazia.");
   
   if (size == 1) {
      auto volta = head->data();
      this->clear();
      return volta;
   }
   
   Node *aux = head->next();
   auto volta = head->data();
   head = aux;
   size--;
   return volta;
}

/** remover específico */
template<typename T>
void  LinkedQueue<T>::remove(const T& data) {
   if (empty()) {
      throw std::out_of_range("Lista Vazia");
   }
   else if (head->data() == data) {
      pop_front();
   }
   else {
      Node* before = head;
      Node* current = head->next();
      while (current->next() != nullptr) {
         if (current->data() == data) {
            before->next(current->next());
            break;
         }
         before = current;
         current = current->next();
      }
   }
}

template<typename T>
bool LinkedQueue<T>::empty() const {
   return size == 0;
}


template<typename T>
bool LinkedQueue<T>::contains(const T& data) const {
   auto aux = head;
   for (int i = 0; i < size; i++) {
      if (aux->data() == data) {
         flag = 1;
      }
      aux = aux->next();
   } 
}

template<typename T>
int LinkedQueue<T>::find(const T& data) const {
   if (size == 0) 
      throw std::out_of_range("Erro! Lista vazia.");
   
   auto aux = head;
   for (int i = 0; i < size; i++) {
      if (aux->data() == data)
         return i;
      aux = aux->next();
   }
   return -1;
}

template<typename T>
int LinkedQueue<T>::getSize() const {
   return size;
}

#endif

#pragma once
#ifndef INCLUDED_FILA_H
#define INCLUDED_FILA_H

#include <stdexcept>

template<typename T>
class LinkedQueue {
public:
   LinkedQueue();
   ~LinkedQueue();

   void clear();
   void push_back(const T& data); 
   void push_front(const T& data); 
   void insert(const T& data, std::size_t index); 
   void insert_sorted(const T& data); 
   T& at(std::size_t index); 
   T pop(std::size_t index); 
   T pop_back();  
   T pop_front(); 
   void remove(const T& data);  
   bool empty() const; 
   bool contains(const T& data) const;  
   std::size_t find(const T& data) const; 
   std::size_t size() const;

private:
   struct  Node 
   {   
      ~Node() = default;
      Node() {}
      Node(const T& data) : data_{ data } {}
      Node(const T& data, Node* next) : data_{ data }, next_{ next } {}      

      T& getData() {  return data_; }

      Node* getNext() {  return next_; }
      void setNext(Node* node) { next_ = node; }

   private:
      T data_{nullptr};
      Node* next_{ nullptr };
   };

   Node* end() {
      auto it = head;
      for (auto i = 1u; i < size(); ++i) {
         it = it->next();
      }
      return it;
   }

   Node* head{ nullptr };
   int size_;
};

template<typename T>
LinkedQueue<T>::LinkedQueue() {
   head = nullptr;
   size_ = 0;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
   this->clear();
}

template<typename T>
void LinkedQueue<T>::clear() {
   Node* current = head;
   Node* next;
   while (current != nullptr) {
      next = current->next();
      delete current;
      current = next;
   }
   head = nullptr;
   size_ = 0;
}

template<typename T>
void LinkedQueue<T>::push_back(const T& data) {
   if (empty()) {
      push_front(data);
   }
   else {
      end()->next(new Node(data));
      size_++;
   }
}

template<typename T>
void LinkedQueue<T>::push_front(const T& data) {
   Node *novo = new Node(data);
   if (novo == nullptr) 
      throw std::out_of_range("Erro! Lista cheia.");
   
   novo->next(head);
   head = novo;
   size_++;   
}

template<typename T>
void LinkedQueue<T>::insert(const T& data, std::size_t index) {
   if (index > size_ || index < 0)
      throw std::out_of_range("Index error");
   if (empty()) {
      //  push_front(data);
      Node *novo = new Node(data);
      novo->next(head);
      head = novo;
      size_++;
   }
   else {
      auto aux = head;
      for (int i = 1; i < index; i++)
         aux = aux->next();
      aux->next(new Node(data, aux->next()));
      size_++;
   }
}

template<typename T>
void LinkedQueue<T>::insert_sorted(const T& data) {
   if (empty()) {
      push_front(data);
   }
   else {
      auto atual = head;
      int pos = 1;
      while (atual->next() != nullptr && data > atual->data()) {
         atual = atual->next();
         pos++;
      }
      if (data > atual->data()) {
         insert(data, pos + 1);
      }
      else {
         insert(data, pos);
      }
   }
}

template<typename T>
T& LinkedQueue<T>::at(std::size_t index) {
   if (index > size_ || index < 0)
      throw std::out_of_range("Erro! Posição não existe.");
   Node *aux = head;
   for (int i = 0; i < index; i++) {
      aux = aux->next();
   }
   return aux->data();
}

template<typename T>
T LinkedQueue<T>::pop(std::size_t index) {
   Node* temp_node = head;;
   if (index > size_ || index < 0) 
      throw std::out_of_range("Erro de index");
   
   if (index == 1) 
      head = temp_node->next();   

   else if (index == size_) {
      while (temp_node->next() != nullptr)
         temp_node = temp_node->next();
      temp_node->next(nullptr);
   }
   else {
      for (int i = 0; i < index - 1; i++)
         temp_node = temp_node->next();
      temp_node->next(temp_node->next());
   }
   size_--;
   return temp_node->data();
}

template<typename T>
T LinkedQueue<T>::pop_back() {
   if (size_ == 0) {
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
   size_--;
   return volta;
}

/** retirar do início */
template<typename T>
T LinkedQueue<T>::pop_front() {
   if (size_ == 0) 
      throw std::out_of_range("Erro! Lista vazia.");
   
   if (size_ == 1) {
      auto volta = head->data();
      this->clear();
      return volta;
   }
   
   Node *aux = head->next();
   auto volta = head->data();
   head = aux;
   size_--;
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
   return size_ == 0;
}


template<typename T>
bool LinkedQueue<T>::contains(const T& data) const {
   int flag = 0;
   Node *aux = head;
   for (int i = 0; i < size_; i++) {
      if (aux->data() == data) {
         flag = 1;
      }
      aux = aux->next();
   }
   free(aux);
   return flag == 1;   
}

template<typename T>
std::size_t LinkedQueue<T>::find(const T& data) const {
   if (size_ == 0) 
      throw std::out_of_range("Erro! Lista vazia.");
   
   Node *aux = head;
   for (int i = 0; i < size_; i++) {
      if (aux->data() == data)
         return i;
      aux = aux->next();
   }
   return size_;
}

template<typename T>
std::size_t LinkedQueue<T>::size() const {
   return size_;
}

#endif

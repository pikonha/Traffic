// Copyright 2018
#pragma once

#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

template<typename T>
class LinkedList {
 public:
    LinkedList();
    ~LinkedList();

    void clear();

    void push_back(const T& data);

    void push_front(const T& data);

    void insert(const T& data, std::size_t index);

    void insert_sorted(const T& data);
 
    T pop(std::size_t index);

    T pop_back();

    T pop_front();

    void remove(const T& data);

    bool empty() const;

    bool contains(const T& data) const;

    std::size_t find(const T& data) const;

    std::size_t size() const;

    T& at(std::size_t index);

    T& at(std::size_t index) const;

 private:
    class Node {  // Elemento
        T data_;
        Node *next_;

      public:
        explicit Node(const T& data):
            data_(data),
            next_(nullptr)
        {}

        Node(const T& data, Node* next):
            data_(data),
            next_(next)
        {}

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        
    };

    Node* end() {  // último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }

    Node* head;
    std::size_t size_;
};

    template<typename T>
    LinkedList<T>::LinkedList():
        head(nullptr),
        size_(0u)
    {}

    template<typename T>
    LinkedList<T>::~LinkedList() {
        clear();
    }

    template<typename T>
    void LinkedList<T>::push_back(const T& data) {
        Node* novo{new Node(data, nullptr)};
        if (empty()) {
    		head = novo;
    	} else {
    		Node* last = end();
        	last->next(novo);
    	}
        size_++;
    }

    template<typename T>
    void LinkedList<T>::push_front(const T& data) {
        Node* novo{new Node(data, head)};
        if (novo == nullptr) {
            throw std::out_of_range("Lista cheia");
        }
        head = novo;
        size_++;
    }

    template<typename T>
    void LinkedList<T>::insert(const T& data, std::size_t index) {
        if (index > size()) {
            throw std::out_of_range("Posição inválida");
        } else if (empty() || index == 0) {
            push_front(data);
        } else {
            Node* novo{new Node(data)};
            if (novo == nullptr) {
                throw std::out_of_range("Lista cheia");
            }
            Node* anterior = head;
            for (auto i = 0u; i < index-1; ++i) {
                anterior = anterior->next();
            }
            novo->next(anterior->next());
            anterior->next(novo);
            size_++;
        }
    }

    template<typename T>
    void LinkedList<T>::insert_sorted(const T& data) {
        if (empty()) {
            push_front(data);
        } else {
            Node* anterior = head;
            auto index = 0u;
            while (anterior->next() != nullptr && data > anterior->data()) {
                index++;
                anterior = anterior->next();
            }
            if (data > anterior->data()) {
                insert(data, index+1);
            } else {
                insert(data, index);
            }
        }
    }

    template<typename T>
    T LinkedList<T>::pop(std::size_t index) {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        if (index >= size_) {
            throw std::out_of_range("Posição inválida");
        } else if (index == 0) {
            return pop_front();
        } else {
            Node* anterior = head;
            for (auto i = 0u; i < index-1; ++i) {
                anterior = anterior->next();
            }
            Node* atual = anterior->next();
            T requested = atual->data();
            anterior->next(atual->next());
            delete atual;
            size_--;
            return requested;
        }
    }

    template<typename T>
    T LinkedList<T>::pop_back() {
        return pop(size_-1);
    }

    template<typename T>
    T LinkedList<T>::pop_front() {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        Node* atual = head;
        head = head->next();
        T requested = atual->data();
        delete atual;
        size_--;
        return requested;
    }

    template<typename T>
    void LinkedList<T>::remove(const T& data) {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        if (contains(data))
        	pop(find(data));
    }

    template<typename T>
    std::size_t LinkedList<T>::find(const T& data) const {
        Node* anterior = head;
        auto index = 0u;
        while ( (index < size_) && (data != anterior->data()) ) {
            index++;
            anterior = anterior->next();
        }
        return index;
    }

    template<typename T>
    void LinkedList<T>::clear() {
        Node* anterior = head;
        Node* atual = head;
        while (atual != nullptr) {
            anterior = atual;
            atual = atual->next();
            delete anterior;
        }
        head = nullptr;
        size_ = 0u;
    }

    template<typename T>
    std::size_t LinkedList<T>::size() const {
        return size_;
    }

    template<typename T>
    bool LinkedList<T>::empty() const {
        return (size_ == 0);
    }

    template<typename T>
    bool LinkedList<T>::contains(const T& data) const {
        return (find(data) >= 0 && find(data) < size_);
    }

    template<typename T>
    T& LinkedList<T>::at(std::size_t index) {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        if (index >= size_) {
            throw std::out_of_range("Posição inválida");
        } else if (index == 0) {
            return head->data();
        } else {
            Node* atual = head;
            for (auto i = 0u; i < index; ++i) {
                atual = atual->next();
            }
            return atual->data();
        }
    }

    template<typename T>
    T& LinkedList<T>::at(std::size_t index) const {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        if (index >= size_) {
            throw std::out_of_range("Posição inválida");
        } else if (index == 0) {
            return head->data();
        } else {
            Node* atual = head;
            for (auto i = 0u; i < index; ++i) {
                atual = atual->next();
            }
            return atual->data();
        }
    }

#endif
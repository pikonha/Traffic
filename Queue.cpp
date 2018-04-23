#include "stdafx.h"
#include "Queue.h"

template <typename T> Queue<T>::~Queue()
{
   delete[] contents;
}

template <typename T> Queue<T>::Queue(int _maxSize) : maxSize(_maxSize)
{
   size = 0;
   contents = new T[maxSize];
}

template <typename T> T Queue<T>::dequeue()
{
}

template <typename T> void Queue<T>::enqueue(const T& data)
{
}

template <typename T> T& Queue<T>::back()
{
}

template <typename T> void Queue<T>::clear()
{
}

template <typename T> bool Queue<T>::empty()
{
}

template <typename T> bool Queue<T>::full()
{
}
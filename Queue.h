#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
class Queue
{
private:
    T* Elements;
    int MaxSize;
    int Count;

public:
    Queue(int size);
    ~Queue();

    Queue(const Queue& other);
    Queue& operator=(const Queue& other);

    void push(const T& value);
    T pop();

    T& front();
    T& back();

    bool empty() const;
    bool full() const;

    int size() const;
    void clear();

    void show();
};

template <typename T>
Queue<T>::Queue(int size)
{
    if (size <= 0)
        throw std::invalid_argument("Queue size must be greater than zero");

    MaxSize = size;
    Elements = new T[MaxSize];
    Count = 0;
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] Elements;
}

template <typename T>
Queue<T>::Queue(const Queue& other)
{
    MaxSize = other.MaxSize;
    Count = other.Count;

    Elements = new T[MaxSize];

    for (int i = 0; i < Count; i++)
    {
        Elements[i] = other.Elements[i];
    }
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    if (this == &other)
        return *this;

    T* newElements = new T[other.MaxSize];

    for (int i = 0; i < other.Count; i++)
    {
        newElements[i] = other.Elements[i];
    }

    delete[] Elements;

    Elements = newElements;
    MaxSize = other.MaxSize;
    Count = other.Count;

    return *this;
}

template <typename T>
bool Queue<T>::empty() const
{
    return Count == 0;
}

template <typename T>
bool Queue<T>::full() const 
{
    return Count == MaxSize;
}

template <typename T>
void Queue<T>::push(const T& value)
{
    if (full())
        throw std::runtime_error("Queue is full");

    Elements[Count++] = value;
}

template <typename T>
T Queue<T>::pop()
{
    if (empty())
        throw std::runtime_error("Queue is empty");

    T temp = Elements[0];

    for (int i = 1; i < Count; i++)
    {
        Elements[i - 1] = Elements[i];
    }

    Count--;

    return temp;
}

template <typename T>
T& Queue<T>::front()
{
    if (empty())
        throw std::runtime_error("Queue is empty");

    return Elements[0];
}

template <typename T>
T& Queue<T>::back()
{
    if (empty())
        throw std::runtime_error("Queue is empty");

    return Elements[Count - 1];
}

template <typename T>
int Queue<T>::size() const
{
    return Count;
}

template <typename T>
void Queue<T>::clear()
{
    Count = 0;
}
template <typename T>
void Queue<T>::show()
{
    for (int i = 0; i < Count; i++)
    {
        std::cout << Elements[i].GetArrivalTime() << " ";
    }
}

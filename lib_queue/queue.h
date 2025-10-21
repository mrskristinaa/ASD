#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>

template <class T>
class Queue {
private:
    T* _data;
    int _size;
    int _head;
    int _count;

public:
    explicit Queue(int size = 100);
    ~Queue();

    void enqueue(const T& val);
    void dequeue();
    inline T front() const;
    inline bool is_empty() const noexcept;
    inline bool is_full() const noexcept;
    inline int size() const noexcept;
    void clear() noexcept;
};

template <class T>
Queue<T>::Queue(int size) : _size(size), _head(0), _count(0) {
    if (size <= 0) {
        throw std::invalid_argument("Queue size must be positive");
    }
    _data = new T[_size];
}

template <class T>
Queue<T>::~Queue() {
    delete[] _data;
}

template <class T>
void Queue<T>::enqueue(const T& val) {
    if (is_full()) {
        throw std::logic_error("Queue is full");
    }

    int tail = (_head + _count) % _size;
    _data[tail] = val;
    _count++;
}

template <class T>
void Queue<T>::dequeue() {
    if (is_empty()) {
        throw std::logic_error("Queue is empty");
    }

    _head = (_head + 1) % _size;
    _count--;
}

template <class T>
T Queue<T>::front() const {
    if (is_empty()) {
        throw std::logic_error("Queue is empty");
    }
    return _data[_head];
}

template <class T>
bool Queue<T>::is_empty() const noexcept {
    return _count == 0;
}

template <class T>
bool Queue<T>::is_full() const noexcept {
    return _count == _size;
}

template <class T>
int Queue<T>::size() const noexcept {
    return _count;
}

template <class T>
void Queue<T>::clear() noexcept {
    _head = 0;
    _count = 0;
}

#endif // QUEUE_H
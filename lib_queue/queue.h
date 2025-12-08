#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
template <class T>
class Queue {
private:
    T* _data;
    int _head; 
    int _count;     
    int _size;     
public:
    Queue();
    Queue(int size);
    ~Queue();
    void push(const T& val);
    void pop();
    inline T head() const;
    inline bool is_empty() const noexcept;
    inline bool is_full() const noexcept;
    void clear() noexcept;
};
template <class T>
Queue<T>::Queue() : _size(100), _head(0), _count(0) {
    _data = new T[_size];
}
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
void Queue<T>::push(const T& val) {
    if (is_full()) {
        throw std::logic_error("Queue is full");
    }
    int tail = (_head + _count) % _size;
    _data[tail] = val;
    _count++;
}
template <class T>
void Queue<T>::pop() {
    if (is_empty()) {
        throw std::logic_error("Queue is empty");
    }
    _head = (_head + 1) % _size;
    _count--;
}

template <class T>
T Queue<T>::head() const {
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
void Queue<T>::clear() noexcept {
    _head = 0;
    _count = 0;
}
#endif // QUEUE_H
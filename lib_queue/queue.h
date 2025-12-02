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
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    ~Queue();
    void enqueue(const T& val);
    void dequeue();
    inline T front() const;
    inline T back() const;
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
Queue<T>::Queue(const Queue& other) : _size(other._size), _head(other._head), _count(other._count) {
    _data = new T[_size];
    for (int i = 0; i < _count; i++) {
        int index = (other._head + i) % other._size;
        _data[index] = other._data[index];
    }
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {  
        delete[] _data;    

        _size = other._size;
        _head = other._head;
        _count = other._count;

        _data = new T[_size];
        for (int i = 0; i < _count; i++) {
            int index = (other._head + i) % other._size;
            _data[index] = other._data[index];
        }
    }
    return *this;
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
T Queue<T>::back() const {
    if (is_empty()) {
        throw std::logic_error("Queue is empty");
    }
    int tail = (_head + _count - 1) % _size;
    return _data[tail];
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
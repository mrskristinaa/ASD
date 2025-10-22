#pragma once
#ifndef STACK_H
#define STACK_H
#include <stdexcept>
template <class T>
class Stack {
private:
    T* _data;
    int _size;
    int _top;

public:
    explicit Stack(int size = 100);
    ~Stack();

    void push(const T& val);
    void pop();
    inline T top() const;
    inline bool is_empty() const noexcept;
    inline bool is_full() const noexcept;
    void clear() noexcept;
};

template <class T>
Stack<T>::Stack(int size) : _size(size), _top(-1) {
    if (size <= 0) {
        throw std::invalid_argument("Stack size must be positive");
    }
    _data = new T[_size];
}

template <class T>
Stack<T>::~Stack() {
    delete[] _data;
}

template <class T>
void Stack<T>::push(const T& val) {
    if (is_full()) {
        throw std::logic_error("Stack is full");
    }
    _data[++_top] = val;
}

template <class T>
void Stack<T>::pop() {
    if (is_empty()) {
        throw std::logic_error("Stack is empty");
    }
    --_top;
}

template <class T>
T Stack<T>::top() const {
    if (is_empty()) {
        throw std::logic_error("Stack is empty");
    }
    return _data[_top];
}

template <class T>
bool Stack<T>::is_empty() const noexcept {
    return _top == -1;
}

template <class T>
bool Stack<T>::is_full() const noexcept {
    return _top == _size - 1;
}

template <class T>
void Stack<T>::clear() noexcept {
    _top = -1;
}

#endif // STACK_H
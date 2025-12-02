#pragma once
#include <stdexcept>
template <class T>
struct DNode {
    T value;
    DNode<T>* next;
    DNode<T>* prev;  
    DNode(T value_, DNode<T>* prev_ = nullptr, DNode<T>* next_ = nullptr) : value(value_), prev(prev_), next(next_) {
    }
};
template <class T>
class DoublyLinkedList {
    DNode<T>* _head;
    DNode<T>* _tail;
    int _count;
public:
    DoublyLinkedList() : _head(nullptr), _tail(nullptr), _count(0) {}
    DoublyLinkedList(const DoublyLinkedList& other) : _head(nullptr), _tail(nullptr), _count(0) {
        DNode<T>* current = other._head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            clear();
            DNode<T>* current = other._head;
            while (current != nullptr) {
                push_back(current->value);
                current = current->next;
            }
        }
        return *this;
    }
    ~DoublyLinkedList() {
        clear();
    }
    void push_front(const T& val) noexcept {
        DNode<T>* node = new DNode<T>(val, nullptr, _head);
        if (_head != nullptr) {
            _head->prev = node;
        }
        _head = node;
        if (_tail == nullptr) {
            _tail = node;
        }
        _count++;
    }
    void push_back(const T& val) noexcept {
        DNode<T>* node = new DNode<T>(val, _tail, nullptr);
        if (_tail != nullptr) {
            _tail->next = node;
        }
        _tail = node;
        if (_head == nullptr) {
            _head = node;
        }
        _count++;
    }
    void pop_front() {
        if (is_empty()) throw std::logic_error("Error: list is empty");
        DNode<T>* temp = _head;
        _head = _head->next;
        if (_head != nullptr) {
            _head->prev = nullptr;
        }
        else {
            _tail = nullptr;
        }
        delete temp;
        _count--;
    }
    void pop_back() {
        if (is_empty()) throw std::logic_error("Error: list is empty");
        DNode<T>* temp = _tail;
        _tail = _tail->prev;
        if (_tail != nullptr) {
            _tail->next = nullptr;
        }
        else {
            _head = nullptr;
        }
        delete temp;
        _count--;
    }
    void clear() {
        while (!is_empty()) {
            pop_front();
        }
    }
    bool is_empty() const {
        return _head == nullptr;
    }
    int size() const noexcept {
        return _count;
    }
    class Iterator {
        DNode<T>* current;
    public:
        Iterator() : current(nullptr) {}
        Iterator(DNode<T>* pos) : current(pos) {}
        Iterator(const Iterator& other) : current(other.current) {}

        Iterator& operator=(const Iterator& other) {
            if (this != &other) {
                current = other.current;
            }
            return *this;
        }
        T& operator*() {
            if (current == nullptr) throw std::logic_error("Error: dereferencing null iterator");
            return current->value;
        }
        const T& operator*() const {
            if (current == nullptr) throw std::logic_error("Error: dereferencing null iterator");
            return current->value;
        }
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
        Iterator& operator++() {
            if (current != nullptr) {
                current = current->next;
            }
            return *this;
        }
        Iterator operator++(int) {
            Iterator temp = *this;
            if (current != nullptr) {
                current = current->next;
            }
            return temp;
        }
        Iterator& operator--() {
            if (current != nullptr) {
                current = current->prev;
            }
            return *this;
        }
        Iterator operator--(int) {
            Iterator temp = *this;
            if (current != nullptr) {
                current = current->prev;
            }
            return temp;
        }
    };
    Iterator begin() { return Iterator(_head); }
    Iterator end() { return Iterator(nullptr); }
    Iterator rbegin() { return Iterator(_tail); }  
    Iterator rend() { return Iterator(nullptr); } 
};
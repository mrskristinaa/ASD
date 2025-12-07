#pragma once
#include "initializer_list"
#include <stdexcept>
using namespace std;
#define STEP_OF_CAPACITY 15
#define MAX_CAPACITY 10000

template <typename T>
class TVector {
protected:
    T* _data;
    int _size;
    int _capacity;
public:
    TVector();
    TVector(int size);
    TVector(const TVector& other);
    TVector(T* data, int size);
    TVector(std::initializer_list<T> data);
    ~TVector();
    TVector& operator=(const TVector& other);
    void push_front(const T& val);
    void push_back(const T& val);
    void insert(int pos, const T& val);
    void insert(T* pos, const T& val);
    T pop_front();
    T pop_back();
    T crase(int pos);
    T crase(T* pos);
    inline T& front();
    inline const T& front() const;
    inline T& back();
    inline const T& back() const;
    inline int find(const T& val) const;
    void resize(int size);
    void repacking(int pos);
    void clear();
    inline bool isEmpty() const;
    inline bool isFull() const;
    inline T* data() noexcept;
    inline const T* data() const noexcept;
    inline int size() const noexcept;
    inline int capacity() const noexcept;
    inline T& operator[](int indx) noexcept;
    inline const T& operator[](int indx) const noexcept;
    void reserve(int capacity);
    class Iterator {
        T* _ptr;
    public:
        Iterator() : _ptr(nullptr) {}
        Iterator(T* ptr) : _ptr(ptr) {}
        Iterator(const Iterator& other) : _ptr(other._ptr) {}
        Iterator& operator=(const Iterator& other) {
            if (this != &other) {
                _ptr = other._ptr;
            }
            return *this;
        }
        T& operator*() {
            if (_ptr == nullptr) {
                throw std::logic_error("Error: dereferencing null iterator");
            }
            return *_ptr;
        }
        const T& operator*() const {
            if (_ptr == nullptr) {
                throw std::logic_error("Error: dereferencing null iterator");
            }
            return *_ptr;
        }
        T* operator->() {
            return _ptr;
        }
        const T* operator->() const {
            return _ptr;
        }
        bool operator==(const Iterator& other) const {
            return _ptr == other._ptr;
        }
        bool operator!=(const Iterator& other) const {
            return _ptr != other._ptr;
        }
        Iterator& operator++() {
            if (_ptr != nullptr) {
                _ptr++;
            }
            return *this;
        }
        Iterator operator++(int) {
            Iterator temp = *this;
            if (_ptr != nullptr) {
                _ptr++;
            }
            return temp;
        }
        Iterator& operator--() {
            if (_ptr != nullptr) {
                _ptr--;
            }
            return *this;
        }
        Iterator operator--(int) {
            Iterator temp = *this;
            if (_ptr != nullptr) {
                _ptr--;
            }
            return temp;
        }
        Iterator operator+(int n) const {
            return Iterator(_ptr + n);
        }
        Iterator operator-(int n) const {
            return Iterator(_ptr - n);
        }
        Iterator& operator+=(int n) {
            if (_ptr != nullptr) {
                _ptr += n;
            }
            return *this;
        }
        Iterator& operator-=(int n) {
            if (_ptr != nullptr) {
                _ptr -= n;
            }
            return *this;
        }
        int operator-(const Iterator& other) const {
            return _ptr - other._ptr;
        }
    };
    Iterator begin() {
        return Iterator(_data);
    }
    Iterator end() {
        return Iterator(_data + _size);
    }
    Iterator begin() const {
        return Iterator(_data);
    }
    Iterator end() const {
        return Iterator(_data + _size);
    }
    Iterator rbegin() {
        if (_size == 0) return Iterator(nullptr);
        return Iterator(_data + _size - 1);
    }
    Iterator rend() {
        return Iterator(_data - 1); 
    }
protected:
    void reallocate(int new_capacity);
};
template <typename T>
inline TVector<T>::TVector() : _data(nullptr), _size(0), _capacity(0) {}
template <typename T>
inline TVector<T>::TVector(int size) {
    if (size < 0) throw std::logic_error("Size cannot be negative");
    if (size > MAX_CAPACITY) {
        throw std::logic_error("Size must be less than MAX_CAPACITY");
    }
    _size = size;
    _capacity = (_size + STEP_OF_CAPACITY) / STEP_OF_CAPACITY * STEP_OF_CAPACITY;
    if (_capacity == 0 && _size > 0) _capacity = STEP_OF_CAPACITY;
    if (_capacity > 0) {
        _data = new T[_capacity]();
    }
    else {
        _data = nullptr;
    }
}
template <typename T>
inline TVector<T>::TVector(std::initializer_list<T> data) {
    _size = data.size();
    _capacity = (_size + STEP_OF_CAPACITY) / STEP_OF_CAPACITY * STEP_OF_CAPACITY;
    _data = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = *(data.begin() + i);
    }
}
template <typename T>
inline TVector<T>::TVector(const TVector& other) {
    _size = other._size;
    _capacity = other._capacity;
    _data = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}
template <typename T>
inline TVector<T>::TVector(T* data, int size) {
    _size = size;
    _capacity = (_size + STEP_OF_CAPACITY) / STEP_OF_CAPACITY * STEP_OF_CAPACITY;
    _data = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = data[i];
    }
}
template <typename T>
inline TVector<T>::~TVector() {
    if (_data != nullptr) {
        delete[] _data;
    }
}
template <typename T>
inline TVector<T>& TVector<T>::operator=(const TVector& other) {
    if (this != &other) {
        if (_data != nullptr) {
            delete[] _data;
        }
        _size = other._size;
        _capacity = other._capacity;
        _data = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}
template <typename T>
inline void TVector<T>::push_front(const T& val) {
    insert(0, val);
}
template <typename T>
inline void TVector<T>::push_back(const T& val) {
    if (_size >= _capacity) {
        int new_capacity;
        if (_capacity == 0) {
            new_capacity = STEP_OF_CAPACITY;
        }
        else {
            new_capacity = _capacity + STEP_OF_CAPACITY;
        }
        reallocate(new_capacity);
    }
    _data[_size++] = val;
}
template <typename T>
inline void TVector<T>::insert(int pos, const T& val) {
    if (pos < 0 || pos > _size) throw std::logic_error("Position out of range");
    if (_size >= _capacity) {
        int new_capacity;
        if (_capacity == 0) {
            new_capacity = STEP_OF_CAPACITY;
        }
        else {
            new_capacity = _capacity + STEP_OF_CAPACITY;
        }
        reallocate(new_capacity);
    }
    for (int i = _size; i > pos; i--) {
        _data[i] = _data[i - 1];
    }
    _data[pos] = val;
    _size++;
}
template <typename T>
inline void TVector<T>::insert(T* pos, const T& val) {
    if (pos < _data || pos > _data + _size) throw std::logic_error("Pointer out of range");
    int index = static_cast<int>(pos - _data);
    insert(index, val);
}
template <typename T>
inline T TVector<T>::pop_front() {
    if (_size < 1) throw std::logic_error("Vector is empty");
    return crase(0);
}
template <typename T>
inline T TVector<T>::pop_back() {
    if (_size < 1) throw std::logic_error("Vector is empty");
    T value = _data[_size - 1];
    _size--;
    return value;
}
template <typename T>
inline T TVector<T>::crase(int pos) {
    if (pos < 0 || pos > _size) throw std::logic_error("Position out of range");

    T value = _data[pos];
    for (int i = pos; i < _size - 1; i++) {
        _data[i] = _data[i + 1];
    }
    _size--;
    return value;
}
template <typename T>
inline T TVector<T>::crase(T* pos) {
    if (pos < _data || pos > _data + _size) throw std::logic_error("Pointer out of range");
    int index = static_cast<int>(pos - _data);
    return crase(index);
}
template <typename T>
inline T& TVector<T>::front() {
    if (_size < 1) throw std::logic_error("Vector is empty");
    return _data[0];
}
template <typename T>
inline const T& TVector<T>::front() const {
    if (_size < 1) throw std::logic_error("Vector is empty");
    return _data[0];
}
template <typename T>
inline T& TVector<T>::back() {
    if (_size < 1) throw std::logic_error("Vector is empty");
    return _data[_size - 1];
}
template <typename T>
inline const T& TVector<T>::back() const {
    if (_size < 1) throw std::logic_error("Vector is empty");
    return _data[_size - 1];
}
template <typename T>
inline int TVector<T>::find(const T& val) const {
    for (int i = 0; i < _size; i++) {
        if (_data[i] == val) {
            return i;
        }
    }
    return -1;
}
template <typename T>
inline void TVector<T>::resize(int size) {
    if (size < 0) throw std::logic_error("Size cannot be negative");

    if (size > _capacity) {
        int new_capacity = (size + STEP_OF_CAPACITY) / STEP_OF_CAPACITY * STEP_OF_CAPACITY;
        reallocate(new_capacity);
    }

    for (int i = _size; i < size; i++) {
        _data[i] = T();
    }
    _size = size;
}
template <typename T>
inline void TVector<T>::repacking(int pos) {
    if (pos < 0 || pos >= _size) throw std::logic_error("Position out of range");
    if (pos == 0) return;
    T temp = _data[pos];
    for (int i = pos; i > 0; i--) {
        _data[i] = _data[i - 1];
    }
    _data[0] = temp;
}
template <typename T>
inline void TVector<T>::clear() {
    _size = 0;
}
template <typename T>
inline bool TVector<T>::isEmpty() const {
    return _size == 0;
}
template <typename T>
inline bool TVector<T>::isFull() const {
    return _size == _capacity;
}
template <typename T>
inline T* TVector<T>::data() noexcept {
    return _data;
}
template <typename T>
inline const T* TVector<T>::data() const noexcept {
    return _data;
}
template <typename T>
inline int TVector<T>::size() const noexcept {
    return _size;
}
template <typename T>
inline int TVector<T>::capacity() const noexcept {
    return _capacity;
}
template <typename T>
inline T& TVector<T>::operator[](int indx) noexcept {
    return _data[indx];
}
template <typename T>
inline const T& TVector<T>::operator[](int indx) const noexcept {
    return _data[indx];
}
template <typename T>
inline void TVector<T>::reserve(int capacity) {
    if (capacity > _capacity) {
        reallocate(capacity);
    }
}
template <typename T>
inline void TVector<T>::reallocate(int new_capacity) {
    if (new_capacity < _size) {
        new_capacity = _size;
    }
    if (new_capacity == _capacity) return;
    T* new_data;
    if (new_capacity > 0) {
        new_data = new T[new_capacity];
    }
    else {
        new_data = nullptr;
    }
    for (int i = 0; i < _size && i < new_capacity; i++) {
        new_data[i] = _data[i];
    }
    if (_data != nullptr) {
        delete[] _data;
    }
    _data = new_data;
    _capacity = new_capacity;
}
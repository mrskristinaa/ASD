#pragma once
template <class T>
struct Node {
	T value;
	Node<T>* next;
	Node(T value_, Node<T>* next_ = nullptr);
};
template <class T>
class List {
	Node<T>* _head, * _tail;
	int _count;
public:
	List() :_head(nullptr), _tail(nullptr), _count(0) {}
	List(const List& other);
	~List();

	void push_front(const T& val) noexcept;
	void push_back(const T& val) noexcept;
	void insert(int pos, const T& val);
	void insert(Node<T>* node, const T& val);

	void pop_front();
	void pop_back();
	void erase(int pos);
	void erase(Node<T>* node);
	void clear();

	bool is_empty();
	Node<T>* find(const T& val);
};

template <class T>
Node<T>::Node(T value_, Node<T>* next_) : value(value_), next(next_) {}

template <class T>
List<T>::List(const List& other) : _head(nullptr), _tail(nullptr), _count(0) {
	Node<T>* current = other._head;
	while (current != nullptr) {
		push_back(current->value);
		current = current->next;
	}
}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
void List<T>::push_front(const T& val) noexcept {
	Node<T>* node = new Node<T>(val, _head);
	if (is_empty()) _tail = node;
	_head = node;
	_count++;
}

template <class T>
void List<T>::push_back(const T& val) noexcept {
	Node<T>* node = new Node<T>(val);
	if (is_empty()) {
		_head = node;
		_tail = node;
		_count++;
		return;
	}
	_tail->next = node;
	_tail = node;
	++_count;
}

template <class T>
void List<T>::insert(Node<T>* node, const T& val) {
	if (node == nullptr) throw "Error: null node";
	Node<T>* new_node = new Node<T>(val, node->next);
	node->next = new_node;
	if (_tail == node) {
		_tail = new_node;
	}
	_count++;
}

template <class T>
void List<T>::insert(int pos, const T& val) {
	if (pos < 0 || pos > _count) throw "Error: position out of range";

	if (pos == 0) {
		push_front(val);
		return;
	}
	else if (pos == _count) {
		push_back(val);
		return;
	}

	int cur_pos = 0;
	Node<T>* cur = _head;
	while (cur != nullptr) {
		if (cur_pos == pos - 1) break;
		cur_pos++;
		cur = cur->next;
	}
	insert(cur, val);
}

template <class T>
void List<T>::pop_front() {
	if (is_empty()) throw "Error: list is empty";

	Node<T>* temp = _head;
	_head = _head->next;
	delete temp;
	_count--;

	if (_head == nullptr) {
		_tail = nullptr;
	}
}

template <class T>
void List<T>::pop_back() {
	if (is_empty()) throw "Error: list is empty";

	if (_head == _tail) {
		delete _head;
		_head = _tail = nullptr;
		_count = 0;
		return;
	}

	Node<T>* current = _head;
	while (current->next != _tail) {
		current = current->next;
	}

	delete _tail;
	_tail = current;
	_tail->next = nullptr;
	_count--;
}

template <class T>
void List<T>::erase(Node<T>* node) {
	if (node == nullptr || is_empty()) throw "Error: invalid node or empty list";

	if (node == _head) {
		pop_front();
		return;
	}

	Node<T>* prev = _head;
	while (prev != nullptr && prev->next != node) {
		prev = prev->next;
	}

	if (prev == nullptr) throw "Error: node not found in list";

	prev->next = node->next;
	if (node == _tail) {
		_tail = prev;
	}

	delete node;
	_count--;
}

template <class T>
void List<T>::erase(int pos) {
	if (pos < 0 || pos >= _count) throw "Error: position out of range";

	if (pos == 0) {
		pop_front();
		return;
	}

	int cur_pos = 0;
	Node<T>* cur = _head;
	while (cur_pos < pos - 1) {
		cur_pos++;
		cur = cur->next;
	}

	Node<T>* toDelete = cur->next;
	cur->next = toDelete->next;

	if (toDelete == _tail) {
		_tail = cur;
	}

	delete toDelete;
	_count--;
}

template <class T>
void List<T>::clear() {
	while (!is_empty()) {
		pop_front();
	}
}

template <class T>
bool List<T>::is_empty() {
	return _head == nullptr;
}

template <class T>
Node<T>* List<T>::find(const T& val) {
	Node<T>* current = _head;
	while (current != nullptr) {
		if (current->value == val) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}
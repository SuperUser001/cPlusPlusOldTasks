//—оздайте новый класс Queue2  на основе к. List наследованием
#ifndef Queue2List_h_
#define Queue2List_h_
#include "NewList6.h"

class Queue2 : public IndexedList {
	Node *first = nullptr;
	Node *last = nullptr;
	std::size_t s = 0;
public:
	Queue2() :
		first(nullptr),
		last(nullptr), s(0) { }
	~Queue2() { }
	bool empty() const;
	std::size_t getSize() const;
	void Append(const LL);
	void Erase();
	LL Front() const;
	LL Back() const;
};

inline bool Queue2::empty() const {
	return first == nullptr;
}

inline std::size_t Queue2::getSize() const {
	return s;
}

void Queue2::Append(const LL x) {     // Pushing into the queue
	Node *t = new Node(x);
	if (empty()) {
		first = last = t;
		first->prev = last->next = nullptr;
	}
	else {
		t->prev = last;
		last->next = t;
		last = t;
	}
	++s;
}

void Queue2::Erase() {
	if (empty())
		throw std::underflow_error("Underflow!");
	auto t = first;
	first = first->next;
	delete t;
	t = nullptr;
	--s;
}

LL Queue2::Front() const {
	if (empty())
		throw std::underflow_error("Underflow");
	return first->data;
}

LL Queue2::Back() const {
	if (empty())
		throw std::underflow_error("Underflow");
	return last->data;
}

#endif
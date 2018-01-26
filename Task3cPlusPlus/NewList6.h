//Измените реализацию класса List из предыдущей лабы так, чтобы
//каждый узел содержал ТОЛЬКО целое значение (не обяз.уникальное).
//Создайте методя дял добавления нового элемента в конец списка и перед указанным элементом
//списка, считая, что узлысписка пронумернованы, начиная с нуля, метод удаления узла с заданным индексом,
//получения значения элемента с заданным индексом, проверки на пустоту списка

#ifndef NewList_h_
#define NewList_h_


#include <iostream>
#include <stdexcept>

typedef long long LL;
struct Node {
	LL data = 0;
	Node *prev = nullptr, *next = nullptr;
	Node(LL d) :
		data(d),
		prev(nullptr),
		next(nullptr) { }
};


class IndexedList {
protected:
	Node *first = nullptr, *last = nullptr;
	std::size_t s = 0;
public:
	IndexedList() :
		first(nullptr),
		last(nullptr), s(0) { }
	~IndexedList() { }
	std::size_t getSize() const;
	bool empty() const;
	LL getData(std::size_t = 0) const;
	void Append(const LL);	// добавление в конец
	void Insert(const LL, std::size_t = 0);	// вставка в позицию, по умолч. в голову списка
	void Erase(std::size_t = 0);	// удаление по индексу
	void print();
	Node* search(const LL);
};

inline std::size_t IndexedList::getSize() const {
	return s;
}

inline bool IndexedList::empty() const {
	return first == nullptr;
}

inline LL IndexedList::getData(std::size_t pos) const {
	if (pos > s - 1)
		throw std::out_of_range("Out of range");
	if (empty())
		throw std::underflow_error("Underflow!");
	else {
		Node *temp = first;

		for (std::size_t i = 0; i < pos; temp = temp->next, ++i)
			std::cout << i << " ";
		std::cout << std::endl;
		return temp->data;
	}
}

void IndexedList::Append(const LL x) {
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

void IndexedList::Insert(const LL x, std::size_t pos) {
	auto t = new Node(x);
	if (pos > s - 1)
		throw std::out_of_range("Out of range");
	else if (empty() || s == 1) {
		Append(x);
	}
	else if (!pos) {
		t->next = first;
		first->prev = t;
		first = t;
	}
	else if (pos < s - 1) {
		auto temp = first;
		for (std::size_t i = 0; i < pos; temp = temp->next, ++i)
			std::cout << i << " ";

		/*
		* temp->next = t, t->prev = temp, n->prev = t, t->next = n, // insert after an item
		* auto p = temp->prev->prev; p->next = t, t->prev = p, t->next = temp, temp->prev = t;
		* insert before an item
		*/
		/*temp->next = t;
		t->prev = temp;
		n->prev = t;
		t->next = n;*/
		auto p = temp->prev;
		p->next = t;
		t->prev = p;
		t->next = temp;
		temp->prev = t;
	}
	++s;
}

void IndexedList::Erase(std::size_t pos) {
	if (pos > s - 1)
		throw std::out_of_range("Out of range");
	else if (empty())
		throw std::underflow_error("Underflow!");
	else {
		if (!pos) {
			auto t = first;
			first = first->next;
			delete t;
			t = nullptr;
		}
		else if (pos == s - 1) {
			auto t = last;
			last = last->prev;
			last->next = nullptr;
			delete t;
			t = nullptr;
		}
		else {
			auto t = first;
			for (std::size_t i = 0; i < pos; t = t->next, ++i)
				std::cout << i << " ";
			std::cout << std::endl;

			auto p = t->prev, n = t->next;
			p->next = n;
			n->prev = p;
			delete t;
			t = nullptr;
		}
		--s;
	}
}

Node* IndexedList::search(const LL key) {
	bool found = false;
	for (auto temp = first; temp != nullptr; temp = temp->next)
		if (key == temp->data) {
			found = true;
			return temp;
		}
	return nullptr;
}

void IndexedList::print() {
	if (empty())
		throw std::underflow_error("No data to print");
	for (auto temp = first; temp != nullptr; temp = temp->next)
		std::cout << temp->data << " ";
	std::cout << std::endl;
}
#endif
//�������� ����� ����� Queue1  �� ������ �. List ����������
#ifndef Queue1List_h_
#define Queue1List_h_
#include "NewList6.h"

template <typename>
class Queue1 {
	List<T> L;
public:
	Queue1() {}
	~Queue1() {}
	bool empty() const; //virtual?
	void push(const T); //���������� � �����
 	void pop(); //������� � ���������
	void print();
private:
	void del();
};

template <typename T>
inline bool Queue1<T>::empty() const { return L.empty(); }

template <typename T> 
void Queue1<T>::push(const T x) { L.addD(x); }

template <typename T>
void Queue1<T>::pop() { L.remove();  }

template <typename T>
void Queue1<T>::print() { L.show(); }

template <typename T>
void Queue1<T>::del() { L.del(); }

#endif
//������ ����������� ��������� ������
#ifndef list_template_h_
#define list_h_
#include <iostream>
//�������� ������� ����������� ����������������
template <class T> class List{
	struct Node {
		T dat;
		Node *next, *prev;
		Node(T dat = 0) : //������������� �����
			d(dat), next(nullptr), prev(nullptr) {}
	};
	Node *first;
public:
	List() : begin(nullptr) {}
	~List() { del(); }
	void addD(T dat); //���������� ���� � ������ ������
	bool insert(T key, T dat); //������� ���� d ����� ����� key
	bool remove(T key);//�������� ����
	void show(); //�������� ������ � ���������
private:
	Node* findD(T key);// �����
	void del();
};

template <class T> 
void  List<T>::addD(T dat){
	Node * pv = new Node(dat);
	if (begin == nullptr) {
		begin = pv;  pv->prev = nullptr; } //������� ������ ������� ������
	else {
		Node *t = begin;
		while (t->next) t = t->next;
		t->next = pv;
		pv->prev = t;	}
}

template <class T>
typename List::Node* List<T>::findD(T key){
	Node *pv = begin;
	while (pv) {
		if (pv->d == key) break;
		pv = pv->next;
	}
	return pv;
}

template <class T>
void List<T>::insert(T key, T dat){
	Node *pk = fine(key);
	if (!pk) return false;
	Node *pv = new Node(dat);
	pv->next = pk->next;
	pv->prev = pk;
	pk->next = pv;
	if (pv->next != nullptr) { (pv->next)->prev = pv; }
	return true;
}

template <class T>
bool List<T>::remove(T key) {
	Node *pv = find(key);
	if (!pv) return false;
	if (pv == begin){
		begin = begin->next;
		begin->prev = nullptr;
	}
	else{
		(pv->prev)->next = pv->next;
		if (pv->next != nullptr) (pv->next)->prev = pv->prev;
	}
	delete pv;
	return true;
}

template <class T> void List<T>::print(){
	Node * pv = begin;
	std::cout << std::endl << " list's elements: ";
	while (pv){
		pv = pv->next;
	}
}

template <class T> List<T>::del(){
	if (begin != nullptr) {
		Node *pv = begin;
		while (pv){
			pv = pv->next;
			delete begin;
			begin = pv;
		}
	}
}
#endif //list_template_h_
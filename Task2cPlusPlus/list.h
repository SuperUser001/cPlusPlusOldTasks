#ifndef list_h_
#define list_h_
#include <iostream>

class List {
	//�������� ��������� �����
	//������ ������� �� ����� ��������� ����� ����� �����������:
	struct Node {
		int d; //�������������� ����,������, ������������ �� ������
		Node *prev, *next; //��������� �� ���������� � ��������� ���� ������
		Node(int dat = 0) : d(dat), next(nullptr), prev(nullptr) {};
	};
	Node *pbeg, *pend; //��������� �� ������ ���� ������
public:
	List() : pbeg(nullptr), pend(nullptr) {}
	~List()  { del(); }
	void addD(int dat); //�������� ����
	//Node* findD(int key); //����� ���� �� �����
	Node *insert(int key, int dat); //������� ���� dat ����� ����� key
	bool removeD(int key); //������� ���� � ��������� ������
	void show(); //���������� ������ � ���������� ���� � ������ �����������
	void show_back();
private: 
	Node *findD(int key); //����� ���� �� �����
	void del();//������� ��� ���� �� ������
};

void List::addD(int dat) {
	Node *pv = new  Node(dat); //�������� ������ ��� ����� ����
	if (pbeg == 0) pbeg = pend = pv; //�.�. ������ ������ ���� ������
	else {
		//��������� ����� ���� � ����������
		pv->prev = pend;
		pend->next = pv;
		pend = pv; 	}
}

List::Node* List::findD(int key){
	Node * pv = pbeg;
	while (pv){
		if (pv->d == key) break;
		pv = pv->next;
	}
	return pv;
}

List::Node* List::insert(int key, int dat){
	if (Node *pkey = findD(key)) {
		Node*pv = new Node(dat); //����� ����
		pv->next = pkey->next;
		pv->prev = pkey;
		pkey->next = pv;
		if (pkey != pend) (pv->next)->prev = pv;
		else pend = pv;
		return pv;
	}
	return 0;
}

bool List::removeD(int key){
	if (Node * pk = findD(key)){
		if (pk == pbeg) {
			pbeg = pbeg->next;
			pbeg->prev = nullptr; }
		if (pk == pend){
			pend = pend->prev;
			pend->next = nullptr; }
		else {
			(pk->next)->prev = pk->prev;
			(pk->prev)->next = pk->next;	}
		delete pk;
		return true; 	}
	return false;
}

void List::show() {

	Node *pv = pbeg;
	std::cout << std::endl << "list's elements: ";
	while(pv) {
		std::cout << pv->d;
		pv = pv->next;
	}
	delete pv;
	std::cout << std::endl;
}

void List::show_back(){
	Node *pv = pend;
	std::cout << std::endl << "list's elements show_back: ";
	while (pv){
		std::cout << pv;
		pv = pv->prev;
	}
	std::cout << std::endl;
}

void List::del(){
	if (pbeg != nullptr) {
		Node *pv = pbeg;
		while (pv) {
			pv = pv->next;
			delete pbeg;
			pbeg = pv;	}
	}
}

#endif //list_h_
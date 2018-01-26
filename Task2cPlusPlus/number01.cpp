//2. Создайте класс, реализующий простое текстовое меню. Используйте его для тестирования созданного в предыдущем задании класса List.
/*

#include "list.h"
#include <string>
int main() {
	using namespace std;
	List  L;
	int n;
	cin >> n;       
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		L.addD(t);
	}
	L.show();
	system("pause");
	return 0;
}
*/

#include <iostream>
#include "list.h"
#include "menutest.h"

using namespace std;

void test_List() {
	List lst;
	TMenu lst_menu(4);

	lst_menu.add("void addData(int key, const char *data);", [&lst]() {
		int key;
		char data[10];

		cout << "\t key: ";
		cin >> key;
//		cout << "\t data: ";
//		cin >> data;

/*		try {
			lst.addD(key, data);
		}
		catch (List::KeyExistsException e) {
			cerr << e.what() << endl;
		}
	});
*/
	lst_menu.add("void delData(int key);", [&lst]() {
		try {
			int num;
			cout << "\t num: ";
			cin >> num;
			lst.delData(num);

		}
		catch (List::KeyNotFound e) {
			cerr << e.what() << endl;
		}
		catch (List::EmptyList e) {
			cerr << e.what() << endl;
		}
	});


	lst_menu.add("const char* findData(int key);", [&lst]() {
		cout << "\t key: ";
		int key;
		cin >> key;
		try {
			cout << lst.findData(key) << endl;
		}
		catch (List::KeyNotFound e) {
			cerr << e.what() << endl;
		}
		catch (List::EmptyList e) {
			cerr << e.what() << endl;
		}
	});

	lst_menu.add("void show();", [&lst]() {
		try {
			lst.show();
		}
		catch (List::EmptyList e) {
			cerr << e.what() << endl;
		}
	});

	while (true) {
		lst_menu.show();
		lst_menu.input();
	}
}

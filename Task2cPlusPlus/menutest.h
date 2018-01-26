#ifndef menutest_h_
#define menutest_h_
#include <iostream>
#include <cstring>
#include <functional>

class TMenu {
	struct Item {
		char *name;
		std::function<void(void)> func;
	};
	int size, count;
	Item *items;
public:
	TMenu(int size = 10)
		: size(size), count(0) {
		items = new Item[size];
	}
	~TMenu() {
		for (int i = 0; i < count; ++i)
			free(items[i].name);
		delete[] items;
	}

	void add(const char *name, std::function<void(void)> func) {
		if (count == size) {
			std::cerr << "TMenu::items[] is full!" << std::endl;
			return;
		}
		items[count].func = func;
		items[count].name = strdup(name);
		count++;
	}

	void show() {
		for (int i = 0; i < count; ++i) {
			std::cout << i << ')' << ' ' << items[i].name << std::endl;
		}
	}

	void input() {
		int ch;
		std::cout << "\nEnter [0-" << count - 1 << "]:";
		std::cin >> ch;

		clrscr();

		if ((ch >= 0) && (ch < count))
			items[ch].func();
		else {
			show();
			std::cerr << "Invalid menu item number" << std::endl;
		}
	}

	static void clrscr() {
		system("clear");
	}
};

#endif // TMENU_H

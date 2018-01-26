#include "Queue2List.h"
#include <cstdlib>

int main() {
	using namespace std;
	Queue2 q2;
	q2.Append(7);
	q2.Append(-21);
	q2.Append(-50);
	q2.Append(18);
	q2.Append(8);
	try {
		cout << "Front: " << q2.Front() << " Back: " << q2.Back() << endl;
		q2.Erase();
		cout << "Front: " << q2.Front() << endl;
		while (!q2.empty()) q2.Erase();
		cout << "Front: " << q2.Front() << endl;
		q2.Erase();
	}
	catch (const underflow_error &ue) {
		cerr << "Error: " << ue.what() << endl;
	}

	system("pause");
	return 0;
}
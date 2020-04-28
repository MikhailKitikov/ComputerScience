#include "Libs.h"
#include "Queue.h"
#include "Visitor.h"
#include "Iterator.h"

using namespace std;

int imain() {
	setlocale(LC_ALL, ".1251");

	try {
		Queue<int> q;
		for (int i = 0; i < 10; ++i) {
			q.push_back(i);
		}
		string s;
		cout << "The maximum element in the queue is " << q.max() << endl;
		q.push_back(99);
		q.push_back(-99);
		cout << "The minimum element in the queue is " << q.min() << endl;
		cout << "The maximum element in the queue is " << q.max() << endl;
		
	}
	catch (exception& e) {
		cout << e.what();
	}

	system("pause");
	return 0;
}
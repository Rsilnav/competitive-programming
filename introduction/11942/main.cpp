#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	cout << "Lumberjacks:" << endl;
	for (int i=0; i<cases; i++) {
		bool asc = false;
		bool ordered = true;
		int last;
		cin >> last;

		int now;
		cin >> now;
		if (now > last) {
			asc = true;
		}

		for (int j=0; j<8; j++) {
			cin >> now;
			if (!ordered)
				continue;
				
			if (asc && now < last) {
				ordered = false;
			}
			else if (!asc && now > last) {
				ordered = false;
			}
			last = now;
		}

		if (ordered) {
			cout << "Ordered" << endl;
		}
		else {
			cout << "Unordered" << endl;
		}
	}
	return 0;
}

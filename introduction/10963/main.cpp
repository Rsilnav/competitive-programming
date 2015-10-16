#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	cin.ignore();
	for(int i=0; i<cases; i++) {
		int flag = true;
		int cols;
		cin >> cols;
		int dif;
		int a, b;
		cin >> a >> b;
		dif = a - b;
		for (int j=0; j<cols-1; j++) {
			cin >> a >> b;
			if (flag && a - b != dif) {
				flag = false;
			}
		}
		if (flag) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		if (i < cases-1)
			cout << endl;
	}
	return 0;
}

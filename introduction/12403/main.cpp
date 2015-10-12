#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int ops;
	string op;
	int num;
	int money = 0;
	cin >> ops;
	for (int i=0; i<ops; i++) {
		cin >> op;
		if (op == "donate") {
			cin >> num;
			money += num;
		}
		else if (op == "report") {
			cout << money << endl;
		}
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int ini, x;
	while (cin >> ini && ini) {
		if (ini <= 100) {
			cout << "f91(" << ini << ") = 91" << endl;
		}
		else {
			cout << "f91(" << ini << ") = " << ini-10 << endl;
		}
	}
	return 0;
}

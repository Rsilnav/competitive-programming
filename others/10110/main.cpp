#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	unsigned int num;
	while (cin >> num && num) {
		unsigned int d = (unsigned int)(sqrt(num)+0.5);
		if (num == d*d) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}

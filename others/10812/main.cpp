#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	long a, b;
	for (int i=0; i<cases; i++) {
		cin >> a >> b;
		if (b > a || (a+b)%2==1) {
			cout << "impossible" << endl;
		}
		else {
			cout << (a+b)/2 << " " << (a-b)/2 << endl;
		}
	}
	return 0;
}

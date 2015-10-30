#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	long a;
	while (cin >> a && a >= 0) {
		cout << a*(a+1)/2+1 << endl;
	}
	return 0;
}

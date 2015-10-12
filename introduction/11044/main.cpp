#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases, m, n;
	cin >> cases;
	for (int i=0; i<cases; i++) {
		cin >> m >> n;
		m = m / 3;
		n = n / 3;
		cout << (m*n) << endl;
	}
	return 0;
}

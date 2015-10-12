#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	int n;
	for (int i=0; i<cases; i++) {
		cin >> n;
		int x = n*315 + 36962;
		if (x < 0)
			x *= -1;
		cout << (x/10)%10 << endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases, sum, a, b;
	cin >> cases;
	for (int i=0; i<cases; i++) {
		sum = 0;
		cin >> a >> b;
		for (int j=a; j<=b; j++) {
			if (j%2==1) {
				sum += j;
			}
		}
		cout << "Case " << i+1 << ": " << sum << endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int a, b;
	while (cin >> a >> b) {
		if (a == -1 && b == -1)
			break;
		int min = 0;
		int temp;
		if (a > b) {
			temp = a;
			a = b;
			b = temp;
		}
		min = b - a;
		temp = a +100 - b;
		if (temp < min)
			min = temp;
		cout << min << endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases, shops, shop;
	int min, max;

	cin >> cases;
	for (int i=0; i<cases; i++) {
		cin >> shops;
		min = 100;
		max = 0;
		for (int j=0; j<shops; j++) {
			cin >> shop;
			if (shop > max)
				max = shop;
			if (shop < min)
				min = shop;
		}
		cout << (max-min)*2 << endl;
	}
	return 0;
}

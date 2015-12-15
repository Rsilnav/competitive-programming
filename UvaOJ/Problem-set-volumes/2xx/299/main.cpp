#include <iostream>

using namespace std;

int rails[50] = {0};

int main() {
	ios_base::sync_with_stdio (false);
	int cases, trains, swaps;
	cin >> cases;
	for (int i=0; i<cases; i++) {
		swaps = 0;
		cin >> trains;
		for (int j=0; j<trains; j++) {
			cin >> rails[j];
		}

		bool swapped;
		int temp;
		while (true) {
			swapped = false;
			for (int x=0; x<trains-1; x++) {
				if (rails[x] > rails[x+1]) {
					temp = rails[x];
					rails[x] = rails[x+1];
					rails[x+1] = temp;
					swapped = true;
					swaps++;
				}
			}
			if (!swapped)
				break;
		}
		cout << "Optimal train swapping takes " << swaps << " swaps." <<endl;
	}
	return 0;
}

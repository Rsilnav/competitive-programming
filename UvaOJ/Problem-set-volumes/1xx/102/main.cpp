#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int b1,g1,c1,b2,g2,c2,b3,g3,c3;
	int sum[6], min=2147483647;
	bool found;
	while (cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3) {
		min = 2147483647;
		sum[0] = b2 + b3 + c1 + c3 + g1 + g2;
		sum[1] = b2 + b3 + g1 + g3 + c1 + c2;
		sum[2] = c2 + c3 + b1 + b3 + g1 + g2;
		sum[3] = c2 + c3 + g1 + g3 + b1 + b2;
		sum[4] = g2 + g3 + b1 + b3 + c1 + c2;
		sum[5] = g2 + g3 + c1 + c3 + b1 + b2;

		for (int i=0; i<6; i++) {
			if (sum[i] <= min) {
				min = sum[i];
			}
		}

		found = false;
		for (int i=0; i<6 && !found; i++) {
			if (sum[i] == min) {
				found = true;
				switch(i) {
					case 0:
						cout << "BCG ";
						break;
					case 1:
						cout << "BGC ";
						break;
					case 2:
						cout << "CBG ";
						break;
					case 3:
						cout << "CGB ";
						break;
					case 4:
						cout << "GBC ";
						break;
					case 5:
						cout << "GCB ";
						break;
				}
			}
		}

		cout << min << endl;

	}
	return 0;
}

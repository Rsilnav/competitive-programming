#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);

	int cases;
	int boxes;
	cin >> cases;
	for (int i=0; i<cases; i++) {
		cin >> boxes;
		int min = boxes*6;
		int sum;

		int x = cbrt(boxes);
		if (x*x*x == boxes) {
			min = x*x*6;
		}
		else {
			int y, c, suma;
			for (int a=1; a<=x; a++) {
				if (boxes%a != 0) continue;
				y = sqrt(boxes/a);
				for (int b=1; b<=y; b++) {
					if (boxes%(a*b) != 0) continue;
					c = boxes/(a*b);
					suma = 2*a*b + 2*a*c + 2*b*c;
					if (suma < min) min = suma;
				}
			}
		}
		cout << min << endl;
	}

	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	for (int i=0; i<cases; i++) {
		int walls;
		int low = 0, high = 0;
		cin >> walls;
		int last = -1;
		int now = 0;
		for (int j=0; j<walls; j++) {
			if (last < 0) {
				cin >> last;
			}
			else {
				cin >> now;
				if (now > last) {
					high++;
				}
				else if (now < last) {
					low++;
				}
				last = now;
			}
		}
		printf("Case %d: %d %d\n", i+1, high, low);
	}
	return 0;
}

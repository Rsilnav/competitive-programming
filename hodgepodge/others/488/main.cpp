#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases, amp, freq;
	cin >> cases;
	for (int i=0; i<cases; i++) {
		if (i >= 1)
			cout << endl;
		cin >> amp >> freq;
		for (int j=0; j<freq; j++) {
			if (j > 0)
				cout << endl;
			for (int k=1; k<=amp; k++) {
				for (int l=0; l<k; l++) cout << k;
				cout << endl;
			}
			for (int k=amp-1; k>0; k--) {
				for (int l=0; l<k; l++) cout << k;
				cout << endl;
			}
		}
	}
	return 0;
}

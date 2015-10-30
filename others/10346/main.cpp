#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cigs, k, butts, smoked;
	while (cin >> cigs >> k) {
		smoked = 0;
		butts = 0;
		while (cigs > 0) {
			butts += cigs;
			smoked += cigs;
			cigs = butts/k;
			butts = butts%k;
		}
		cout << smoked << endl;
	}
	return 0;
}

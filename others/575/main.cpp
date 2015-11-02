#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string skew;
	long pos, mul;
	long dec;
	while (getline(cin, skew) && skew != "0") {

		char c;
		for (int i=0, len = skew.size()-1; i<=len; i++, len--) {
			c = skew[i];
			skew[i] = skew[len];
			skew[len] = c;
		}

		dec = 0;
		int sum;
		for (int i=0; i<skew.size(); i++) {
			mul = pow(2, i+1)-1;
			sum = mul * (skew[i] - 48);
			dec += sum;
		}

		cout << dec << endl;

	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int a, b, x, y, carry, temp;
	while (cin >> a >> b) {
		if (a == 0 && b == 0)
			break;

		carry = 0;
		temp = 0;
		while (a != 0 || b != 0) {
			x = a%10;
			a /= 10;
			y = b%10;
			b /= 10;
			if (x+y+temp > 9) {
				temp = (x+y+temp)/10;
				carry += temp;
			}
			else {
				temp = 0;
			}
		}
		if (carry == 0) {
			cout << "No carry operation." << endl;
		}
		else if (carry == 1){
			cout << "1 carry operation." << endl;
		}
		else {
			cout << carry << " carry operations." << endl;
		}
	}
	return 0;
}

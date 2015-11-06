#include <iostream>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int exponente;
	double res;
	long base;
	while (cin >> exponente) {
		cin >> res;
		base = exp(log(res) / exponente) + 0.5;
		cout << base << endl;
	}
	return 0;
}

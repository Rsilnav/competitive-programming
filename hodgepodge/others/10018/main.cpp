#include <iostream>

using namespace std;

long long reverse(long long n) {
	long long t = 0;
	while (n > 0) {
		t *= 10;
		t += (n%10);
		n = n / 10;
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	long long num;
	for (int i=0; i<cases; i++) {
		cin >> num;
		int count = 1;
		num += reverse(num);
		while (num != reverse(num)) {
			num += reverse(num);
			count++;
		}
		cout << count << " " << num << endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s;
	int counter = 1;
	int a,b, temp;
	while (cin >> s) {
		int cases;
		cin >> cases;
		cout << "Case " << counter << ":" << endl;

		for (int i=0; i<cases; i++) {

			bool flag = true;
			cin >> a >> b;
			if (a > b) {
				temp = b;
				b = a;
				a = temp;
			}

			for (int j=a+1; j<b+1; j++) {
				if ((char)s[j] != (char)s[j-1]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		counter++;
	}
	return 0;
}

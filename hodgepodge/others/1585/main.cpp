#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	cin.ignore();
	string s;
	int puntos;
	int sum;
	char c;
	while (cases--) {
		getline(cin, s);
		puntos = 0;
		sum = 0;
		for (int i=0; i<s.size(); i++) {
			c = s.at(i);
			if (c == 'O') {
				sum++;
				puntos += sum;
			}
			else {
				sum = 0;
			}
		}
		cout << puntos << endl;
	}
	return 0;
}

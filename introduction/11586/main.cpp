#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	cin.ignore();
	int emes, efes;
	string s;
	for (int i=0; i<cases; i++) {
		emes = 0;
		efes = 0;
		getline(cin, s);
		for (int j=0; j<s.size(); j++) {
			if (s.at(j) == 'M')
				emes++;
			if (s.at(j) == 'F')
				efes++;
		}
		if (emes == efes && emes > 1) {
			cout << "LOOP" << endl;
		}
		else {
			cout << "NO LOOP" << endl;
		}
	}
	return 0;
}

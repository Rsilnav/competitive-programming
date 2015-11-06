#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s;
	string word;
	while (cin >> word >> s) {
		int pointer = 0;
		bool encoded = false;
		for (int i=0; i<s.size(); i++) {
			if (s.at(i) == word.at(pointer)) {
				pointer++;
				if (pointer == word.size()) {
					encoded = true;
					break;
				}
			}
		}
		if (encoded) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}

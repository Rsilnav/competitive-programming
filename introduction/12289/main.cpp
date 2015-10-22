#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	string names[] = {
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
		"ten"
	};
	cin >> cases;
	int fails;
	string word;
	for (int i=0; i<cases; i++) {
		cin >> word;
		for (int j=0; j<10; j++) {
			string s = names[j];
			if (s.size() != word.size())
				continue;
			fails = 0;

			for (int k=0; k<s.size()-1; k++) {
				if (s[k] != word[k])
					fails++;
			}
			if (fails <= 1) {
				cout << j+1 << endl;
				break;
			}
		}
	}
	return 0;
}

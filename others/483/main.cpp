#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s;
	int j;
	while (getline(cin, s)) {
		for (int i=0; i<s.size(); i++) {
			if (s.at(i) == ' ' || i == s.size()-1) {
				if (s.at(i) != ' ')
					cout << s.at(i);
				j = i-1;
				while (j >= 0 && s.at(j) != ' ') {
					cout << s.at(j);
					j--;
				}
				if (s.at(i) == ' ')
					cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

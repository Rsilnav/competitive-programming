#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	for (int i=0; i<cases; i++) {
		int position = 0;
		int instructions;
		cin >> instructions;
		int moves[instructions];
		for (int j=0; j<instructions; j++) {
			moves[j] = 0;
		}
		string s;
		cin.ignore();
		for (int j=0; j<instructions; j++) {
			getline(cin, s);
			if (s.compare("RIGHT") == 0) {
				position++;
				moves[j] = 1;
			}
			else if (s.compare("LEFT") == 0) {
				position--;
				moves[j] = -1;
			}
			else {
				string t = s.substr(8);
				int x = atoi(t.c_str());
				position += moves[x-1];
				moves[j] = moves[x-1];
			}
		}
		cout << position << endl;
	}
	return 0;
}

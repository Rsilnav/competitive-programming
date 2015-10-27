#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s;
	string result = "";
	int num;
	char c;
	getline(cin, s);
	while (getline(cin, s)) {
		if (s.at(1) != ' ')
			break;
		num = 0;
		for (int i=2; i<s.size()-1; i++) {
			if (s.at(i) == ' ') {
				num = num << 1;
			}
			else if (s.at(i) == 'o') {
				num = num << 1;
				num = num | 1;
			}
		}
		result += (char)num;
	}
	cout << result;
	return 0;
}

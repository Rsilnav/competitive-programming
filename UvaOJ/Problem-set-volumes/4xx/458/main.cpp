#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s;
	string res;
	char c;
	while (getline(cin, s)) {
		res = "";
		for (int i=0; i<s.size(); i++) {
			c = s.at(i);
			res += c-7;
		}
		cout << res << endl;
	}
	return 0;
}

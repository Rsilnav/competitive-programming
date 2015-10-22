#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);

	string q1 = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	string q2 = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
	string d1 = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
	string d2 = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

	string s;
	char c;
	while (getline(cin, s)) {
		for (int i=0; i<s.size(); i++) {
			c = s.at(i);
			if (c == ' ') {
				cout << " ";
				continue;
			}
			for (int j=0; j<q1.size(); j++) {
				if (c == q1[j]) {
					cout << d1[j];
					break;
				}
				else if (c == q2[j]) {
					cout << d2[j];
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

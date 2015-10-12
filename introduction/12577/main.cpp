#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int c = 1;
	string s;
	while (getline(cin, s) && s != "*") {
		cout << "Case " << c << ": ";
		if (s == "Hajj") {
			cout << "Hajj-e-Akbar" << endl;
		}
		else if (s == "Umrah") {
			cout << "Hajj-e-Asghar" << endl;
		}
		c++;
	}
	return 0;
}

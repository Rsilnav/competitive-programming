#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string line;
	int c = 1;
	while (getline(cin, line) && line != "#") {
		cout << "Case " << c << ": ";
		if (line == "HELLO") {
			cout << "ENGLISH";
		}
		else if (line == "HOLA") {
			cout << "SPANISH";
		}
		else if (line == "HALLO") {
			cout << "GERMAN";
		}
		else if (line == "BONJOUR") {
			cout << "FRENCH";
		}
		else if (line == "CIAO") {
			cout << "ITALIAN";
		}
		else if (line == "ZDRAVSTVUJTE") {
			cout << "RUSSIAN";
		}
		else {
			cout << "UNKNOWN";
		}
		cout << endl;
		c++;
	}
	return 0;
}

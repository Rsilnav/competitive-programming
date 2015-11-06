#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	bool valid;
	char c;
	string line;
	cin >> cases;
	cin.ignore();
	for (int i=0; i<cases; i++) {
		getline(cin, line);
		stack<char> pila;
		valid = true;
		for (int j=0; j<line.size(); j++) {
			c = line.at(j);
			if (pila.empty() && (c==']' || c==')')) {
				valid = false;
				break;
			}
			else if (!pila.empty() && c==']') {
				if (pila.top() == '[') {
					pila.pop();
				}
				else {
					valid = false;
					break;
				}
			}
			else if (!pila.empty() && c==')') {
				if (pila.top() == '(') {
					pila.pop();
				}
				else {
					valid = false;
					break;
				}
			}
			else {
				pila.push(c);
			}
		}
		if (valid && pila.empty()) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}

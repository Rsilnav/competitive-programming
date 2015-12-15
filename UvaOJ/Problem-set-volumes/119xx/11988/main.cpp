#include <iostream>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s;
	list<char> lista;
	bool init;
	list<char>::iterator it;
	while (cin >> s) {
		init = false;
		for (int i=0; i<s.size(); i++) {
			if (s.at(i) == '[')  {
				init = true;
				it = lista.begin();
			}
			else if (s.at(i) == ']')  {
				init = false;
			}
			else {
				if (init) {
					lista.insert(it, s.at(i));
				}
				else {
					lista.push_back(s.at(i));
				}
			}
		}
		for (list<char>::iterator it = lista.begin(); it!=lista.end(); it++) {
			cout << *it;
		}
		cout << endl;
		lista.clear();
	}
	return 0;
}

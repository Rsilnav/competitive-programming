#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int nums;
	string s;
	cin >> nums;
	cin.ignore();
	getline(cin, s);
	getline(cin, s);
	getline(cin, s);
	getline(cin, s);
	for (int i=0; i<s.size(); i+=4) {
		if (s.at(i) == '*')
			cout << "2";
		else if (s.at(i+1) == '*')
			cout << "1";
		else
			cout << "3";
	}
	cout << endl;
	return 0;
}

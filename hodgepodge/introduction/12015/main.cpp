#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	string s;
	cin >> cases;
	for (int i=0; i<cases; i++) {
		int max = 0;
		string s = "";

		int num;
		string name;

		for (int j=0; j<10; j++) {
			cin >> name >> num;
			if (num > max) {
				max = num;
				s = "";
				s = s.append(name);
			}
			else if (num == max) {
				s = s.append("\n");
				s = s.append(name);
			}
		}
		cout << "Case #" << i+1 << ":" << endl << s << endl;
	}
	return 0;
}

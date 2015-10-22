#include <iostream>
#include <bitset>

using namespace std;


int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	cin.ignore();

	char datos[8][80] = {0};
	int size;
	string s;
	while (cases--) {
		getline(cin, s);
		size = s.size() - 2;
		for (int i=0; i<8; i++) {
			getline(cin, s);
			for (int j=1; j<size+1; j++) {
				datos[i][j-1] = s.at(j);
			}
		}

		int num;
		for (int i=0; i<size; i++) {
			num = 0;
			for (int j=7; j>=0; j--) {
				if (datos[j][i] == '/') {
					num <<= 1;
				}
				else {
					num <<= 1;
					num |= 1;
				}
			}
			cout << char(num);
		}
		cout << endl;

		getline(cin, s);
		getline(cin, s);
	}
	return 0;
}

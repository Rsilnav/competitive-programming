#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int banks, debentures;
	while (cin >> banks >> debentures) {
		if (banks == 0 && debentures == 0)
			break;
		int money[banks];
		for (int i=0; i<banks; i++) {
			cin >> money[i];
		}
		int debtor, creditor, value;
		for (int i=0; i<debentures; i++) {
			cin >> debtor >> creditor >> value;
			money[debtor-1] -= value;
			money[creditor-1] += value;
		}
		bool flag = true;
		for (int i=0; i<banks; i++) {
			if (money[i] < 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "S" << endl;
		}
		else {
			cout << "N" << endl;
		}
	}
	return 0;
}

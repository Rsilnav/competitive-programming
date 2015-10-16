#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int requirements, proposals;
	int rfp = 1;
	while (cin >> requirements >> proposals) {
		if (requirements == 0 && proposals == 0)
			break;
		if (rfp > 1)
			cout << endl;
		cin.ignore();
		string x;
		for (int i=0; i<requirements; i++) {
			getline(cin, x);
		}

		string nameMax;
		float costMax = 0;
		int complianceMax = 0;
		string name;
		float cost;
		int parts;

		string part;
		for (int i=0; i<proposals; i++) {
			getline(cin, name);
			cin >> cost >> parts;
			cin.ignore();
			for (int j=0; j<parts; j++) {
				getline(cin, part);
			}
			if (parts > complianceMax) {
				complianceMax = parts;
				nameMax = name;
				costMax = cost;
			}
			if (parts == complianceMax && cost < costMax) {
				complianceMax = parts;
				nameMax = name;
				costMax = cost;
			}
		}

		cout << "RFP #" << rfp << endl;
		cout << nameMax << endl;
		rfp++;
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int numPersons = 0;

	bool isFirst = true;

	while ((cin >> numPersons) && (numPersons != 0)) {
		if (!isFirst)
			cout << endl;

		string names[numPersons];
		for (int i=0; i<numPersons; i++) {
			cin >> names[i];
		}

		int worth[numPersons];
		for (int i=0; i<numPersons; i++) {
			worth[i] = 0;
		}

		for (int j=0; j<numPersons; j++) {
			string donor;
			int amount;
			int given;
			cin >> donor;
			cin >> amount;
			cin >> given;

			int idDonor;
			for (int i=0; i<numPersons; i++) {
				if (donor.compare(names[i]) == 0) {
					idDonor = i;
					break;
				}
			}

			string givenTo;

			for (int i=0; i<given; i++) {
				cin >> givenTo;
				for (int k=0; k<numPersons; k++) {
					if (givenTo.compare(names[k]) == 0) {
						worth[k] += amount/given;
						worth[idDonor] -= amount/given;
						break;
					}
				}
			}
		}

		for (int i=0; i<numPersons; i++) {
			cout << names[i] << " " << worth[i] << endl;
		}
		numPersons = 0;

		isFirst = false;
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int numSubjects;
	int numCategories;
	while (cin >> numSubjects) {
		if (numSubjects == 0)
			break;
		cin >> numCategories;
		int subs[numSubjects];
		for (int i=0; i<numSubjects; i++) {
			cin >> subs[i];
		}

		bool willPass = true;
		int numSubInCat;
		int numReqs;
		for (int i=0; i<numCategories; i++) {
			cin >> numSubInCat >> numReqs;
			int req;
			for (int j=0; j<numSubInCat; j++) {
				cin >> req;
				for (int k=0; k<numSubjects && willPass && numReqs>0; k++) {
					if (req == subs[k]) {
						numReqs--;
					}
				}
			}
			if (numReqs > 0) {
				willPass = false;
			}
		}

		if (willPass) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}

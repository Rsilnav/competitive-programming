#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int persons;
	cin >> persons;
	string names[persons];
	for (int i=0; i<persons; i++) {
		cin >> names[i];
	}
	int repetitions;
	int singer;
	repetitions = persons/16;
	if (persons%16>0)
		repetitions++;
	int part = 0;

	for (int j=0; j<repetitions*16; j++) {
		cout << names[j%persons] << ": ";
		switch(part%4) {
			case 0:
				cout << "Happy" << endl;
				break;
			case 1:
				cout << "birthday" << endl;
				break;
			case 2:
				cout << "to" << endl;
				break;
			case 3:
				if (j%16==11) {
					cout << "Rujia" << endl;
				}
				else {
					cout << "you" << endl;
				}
				break;
		}
		part++;
		part = part%16;
	}
	return 0;
}

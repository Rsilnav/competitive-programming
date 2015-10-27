#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int numStudents;
	cin >> numStudents;
	string students[numStudents];
	for (int i=0; i<numStudents; i++) {
		cin >> students[i];
	}
	int numQueries;
	cin >> numQueries;
	int query;
	for (int i=0; i<numQueries; i++) {
		cin >> query;
		if (students[query-1].compare("?") != 0) {
			cout << students[query-1] << endl;
		}
		else {
			for (int distance=1; distance<numStudents; distance++) {
				if (query-1-distance >= 0 && query-1+distance < numStudents) {
					if (students[query-1-distance].compare("?") != 0 && students[query-1+distance].compare("?") != 0) {
						cout << "middle of " << students[query-1-distance] << " and " << students[query-1+distance] << endl;
						break;
					}
				}
				if (query-1+distance < numStudents) {
					if (students[query-1+distance].compare("?") != 0) {
						for (int x=0; x<distance; x++) {
							cout << "left of ";
						}
						cout << students[query-1+distance] << endl;
						break;
					}
				}
				if (query-1-distance >= 0) {
					if (students[query-1-distance].compare("?") != 0) {
						for (int x=0; x<distance; x++) {
							cout << "right of ";
						}
						cout << students[query-1-distance] << endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}

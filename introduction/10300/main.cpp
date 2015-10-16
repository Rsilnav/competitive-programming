#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	int farmers;
	int summed;
	cin >> cases;
	int size, animals, environment;
	for (int i=0; i<cases; i++) {
		cin >> farmers;
		summed = 0;
		for (int j=0; j<farmers; j++) {
			cin >> size >> animals >> environment;
			summed += size * environment;
		}
		cout << summed << endl;
	}
	return 0;
}

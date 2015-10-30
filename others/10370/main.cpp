#include <iostream>

using namespace std;

int student[1000] = {0};

int main() {
	ios_base::sync_with_stdio (false);
	int cases, people, above;
	double med, result;
	cin >> cases;
	while (cases--) {
		cin >> people;
		med = 0;
		above = 0;
		for (int i=0; i<people; i++) {
			cin >> student[i];
			med += student[i] ;
		}
		med = med/people;
		for (int i=0; i<people; i++) {
			if (student[i] > med) {
				above++;
			}
		}
		result = 100.0*above/people;
		printf("%.3f%%\n", result);
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int numYears, numPopes;
	int pointer1, pointer2;
	int bestp1, bestp2;
	int year;

	int years[100000];

	while (cin >> numYears) {
		cin >> numPopes;

		for (int i=0; i<numPopes; i++) {
			cin >> year;
			years[i] = year;
		}

		pointer1=0, pointer2=0;
		bestp1=0, bestp2=-1;

		while (pointer2 < numPopes-1 && pointer1 < numPopes-1) {
			//printf("%d - %d\n", pointer1, pointer2);
			if (years[pointer2] - years[pointer1] < numYears) {
				if (pointer2-pointer1 > bestp2-bestp1) {
					bestp1 = pointer1;
					bestp2 = pointer2;
					//printf("FOUND: %d POPES.\n", pointer2-pointer1+1);
					//printf("** %d[%d] - %d[%d]\n", years[pointer1], pointer1, years[pointer2], pointer2);
				}
				pointer2++;
			}
			else {
				pointer1++;
				pointer2++;
			}
		}
		printf("%d %d %d\n", bestp2-bestp1+1, years[bestp1], years[bestp2]);
		cin.ignore();
	}
	return 0;
}

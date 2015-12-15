#include <iostream>

using namespace std;

int piles[50] = {0};

int main() {
	ios_base::sync_with_stdio (false);
	int stacks, sum, med, result;
	int cases = 1;
	while (cin >> stacks && stacks) {
		result = 0;
		sum = 0;
		for (int i=0; i<stacks; i++) {
			cin >> piles[i];
			sum += piles[i];
		}
		med = sum/stacks;
		for (int i=0; i<stacks; i++) {
			if (piles[i] > med) {
				result += piles[i] - med;
			}
		}

		cout << "Set #" << cases << endl;
		cout << "The minimum number of moves is " << result << "." << endl << endl;

		cases++;
	}
	return 0;
}

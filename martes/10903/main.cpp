#include <iostream>

using namespace std;

int wins[100] = {0};
int played[100] = {0};

int main() {
	ios_base::sync_with_stdio (false);
	int n, k, plays;

	double d;
	int p1, p2;
	string m1, m2;

	int a = 0;

	while (cin >> n && n) {
		if (a > 0) {
			printf("\n");
		}
		a++;
		cin >> k;
		plays = k*n*(n-1)/2;

		for (int i=0; i<plays; i++) {
			cin >> p1 >> m1 >> p2 >> m2;

			if (m1 == m2) {
				continue;
			}
			else if (m1 == "rock" && m2 == "scissors"){
				wins[p1-1]++;
			}
			else if (m2 == "rock" && m1 == "scissors"){
				wins[p2-1]++;
			}
			else if (m1 == "paper" && m2 == "rock"){
				wins[p1-1]++;
			}
			else if (m2 == "paper" && m1 == "rock"){
				wins[p2-1]++;
			}
			else if (m1 == "scissors" && m2 == "paper"){
				wins[p1-1]++;
			}
			else if (m2 == "scissors" && m1 == "paper"){
				wins[p2-1]++;
			}
			played[p1-1]++;
			played[p2-1]++;

		}
		for (int i=0; i<n; i++) {
			if (played[i] == 0) {
				printf("-\n");
				continue;
			}
			else {

				d = wins[i]*1.0 /played[i];
				printf("%.3f\n", d);
				wins[i] = 0;
				played[i] = 0;
			}
		}

	}
	return 0;
}

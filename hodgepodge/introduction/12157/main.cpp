#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	for (int i=0; i<cases; i++) {
		int milecost = 0, juicecost = 0;
		int calls;
		cin >> calls;
		int phonecall;
		for (int j=0; j<calls; j++) {
			cin >> phonecall;
			milecost += (phonecall/30)*10;
			if (phonecall - phonecall/30 > 0)
				milecost += 10;
			juicecost += (phonecall/60)*15;
			if (phonecall - phonecall/60 > 0)
				juicecost += 15;
		}
		cout << "Case " << i+1 << ": ";
		if (milecost < juicecost) {
			cout << "Mile " << milecost << endl;
		}
		else if (milecost == juicecost) {
			cout << "Mile Juice " << milecost << endl;
		}
		else if (milecost > juicecost) {
			cout << "Juice " << juicecost << endl;
		}
	}
	return 0;
}

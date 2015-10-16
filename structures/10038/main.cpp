#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	int num;
	int now, last;
	while (cin >> cases) {
		
		bool diffs[cases-1];
		for (int i=0; i<cases-1; i++) {
			diffs[i] = false;
		}
		cin >> now;
		for (int i=0; i<cases-1; i++) {
			last = now;
			cin >> now;
			num = now - last;
			if (num < 0) num*=-1;
			diffs[num-1] = true;
		}
		bool flag = true;
		for (int i=0; i<cases-1; i++) {
			if (diffs[i] == false) {
				cout << "Not jolly" << endl;
				flag = false;
				break;	
			}
		}
		if (flag == true) {
			cout << "Jolly" << endl;
		}
	}
	return 0;
}

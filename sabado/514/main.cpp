#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int tam;
	while (cin >> tam && tam) {
		int num[tam];
		int temp;
		while (cin >> temp && temp) {
			num[0] = temp;
			for (int i=1; i<tam; i++) {
				cin >> num[i];
			}

			stack<int> stationA;
			for (int i=tam; i>0; i--) {
				stationA.push(i);
			}

			stack<int> swapper;

			stack<int> stationB;
			for (int i=tam-1; i>=0; i--) {
				stationB.push(num[i]);
			}

			bool possible = true;
			while (true) {
				if (stationB.empty())
					break;

				if (!stationA.empty() && stationB.top() == stationA.top()) {
					stationB.pop();
					stationA.pop();
				}
				else if (!swapper.empty() && stationB.top() == swapper.top()) {
					stationB.pop();
					swapper.pop();
				}
				else if (!stationA.empty()){
					swapper.push(stationA.top());
					stationA.pop();
				}
				else {
					possible = false;
					break;
				}
			}

			if (possible)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cout << endl;
	}
	return 0;
}

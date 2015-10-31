#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<queue<int>> stations;
stack<int> cargo;

bool hasEnded() {
	bool end = true;
	for (int i=0; i<stations.size(); i++) {
		if (!cargo.empty()) {
			end = false;
			break;
		}
		if (!stations.at(i).empty()) {
			end = false;
			break;
		}
	}
	return end;
}

int main() {
	ios_base::sync_with_stdio (false);
	int sets;
	cin >> sets;
	int timeSpent;
	int numStations;
	int cargoSpace;
	int capPlatB;
	int numPackages;
	int t;
	for (int i=0; i<sets; i++) {
		timeSpent = 0;

		cin >> numStations >> cargoSpace >> capPlatB;

		for (int i=0; i<numStations; i++) {
			queue<int> temp;
			cin >> numPackages;
			for (int j=0; j<numPackages; j++) {
				cin >> t;
				temp.push(t);
			}
			stations.push_back(temp);
		}

		int station = 0;
		int paquete;
		while(!hasEnded()) {
			while(true) {
				if (cargo.empty()) {
					break;
				}
				paquete = cargo.top();
				if (paquete-1 == station) {
					cargo.pop();
					timeSpent++;
				}
				else {
					if (stations.at(station).size() >= capPlatB) {
						break;
					}
					stations.at(station).push(paquete);
					cargo.pop();
					timeSpent++;
				}
			}

			while(true) {
				if (cargo.size() >= cargoSpace) {
					break;
				}
				if (stations.at(station).empty()) {
					break;
				}
				paquete = stations.at(station).front();
				cargo.push(paquete);
				stations.at(station).pop();
				timeSpent+=1;
			}
			station++;
			timeSpent+=2;
			station = station % numStations;
		}

		cout << timeSpent-2 << endl;

		stations.clear();
		while(!cargo.empty()) cargo.pop();
	}
	return 0;
}

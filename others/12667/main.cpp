#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int probs, teams, subs;
	cin >> probs >> teams >> subs;
	bool sent[probs][teams];
	for (int i=0; i<probs; i++) {
		for (int j=0; j<teams; j++) {
			sent[i][j] = false;
		}
	}
	int bestTimes[probs];
	int bestTeams[probs];
	for (int i=0; i<probs; i++) {
		bestTimes[i] = -1;
		bestTeams[i] = -1;
	}
	int tiempo, team;
	char prob;
	string veredict;
	for (int i=0; i<subs; i++) {
		cin >> tiempo >> team >> prob >> veredict;
		if (veredict.compare("Yes") == 0 && !sent[(int)prob-65][team] && tiempo >= bestTimes[(int)prob-65]) {
			bestTimes[(int)prob-65] = tiempo;
			sent[(int)prob-65][team] = true;
			bestTeams[(int)prob-65] = team;
		}
	}
	for (int i=0; i<probs; i++) {
		cout << (char)(65+i) << " ";
		if (bestTimes[i] >= 0) {
			cout << bestTimes[i] << " " << bestTeams[i];
		}
		else {
			cout << "- -";
		}
		cout << endl;
	}
	return 0;
}

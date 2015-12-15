#include <iostream>
#include <vector>

using namespace std;

int inf = 32767;

vector<int> dijk(int A, vector< vector<int> > adj) {
  int n = adj.size();
  vector<int> dist(n);
  vector<bool> vis(n);

  for(int i = 0; i < n; ++i) {
    dist[i] = inf;
  }
  dist[A] = 0;

  for(int i = 0; i < n; ++i) {
    int cur = -1;
    for(int j = 0; j < n; ++j) {
      if (vis[j]) continue;
      if (cur == -1 || dist[j] < dist[cur]) {
        cur = j;
      }
    }
    vis[cur] = true;
    for(int j = 0; j < n; ++j) {
      int path = dist[cur] + adj[cur][j];
      if (path < dist[j]) {
        dist[j] = path;
      }
    }
  }

  return dist;
}


int main() {
	ios_base::sync_with_stdio (false);
	int streets;
	char cPosMe, cPosRev;
	int iPosMe, iPosRev;

	char cAge, cDirection;
	int iAge, iDirection;
	char cPlace1, cPlace2;
	int iPlace1, iPlace2;
	int energy;
	while (cin >> streets && streets) {

		vector<vector<int>> adjMe(26);
		vector<vector<int>> adjRev(26);
		for(int i = 0; i < 26; ++i) {
			adjMe[i] = vector<int>(26);
			adjRev[i] = vector<int>(26);
			for(int j = 0; j < 26; ++j) {
				adjMe[i][j] = inf;
				adjRev[i][j] = inf;
			}
		}

		for (int i=0; i<streets; i++) {
			cin >> cAge >> cDirection >> cPlace1 >> cPlace2 >> energy;
			iPlace1 = (int)cPlace1-65;
			iPlace2 = (int)cPlace2-65;
			if (cAge == 'Y') {
				if (cDirection == 'U') {
					adjMe[iPlace1][iPlace2] = energy;
				}
				else {
					adjMe[iPlace1][iPlace2] = energy;
					adjMe[iPlace2][iPlace1] = energy;
				}
			}
			else {
				if (cDirection == 'U') {
					adjRev[iPlace1][iPlace2] = energy;
				}
				else {
					adjRev[iPlace1][iPlace2] = energy;
					adjRev[iPlace2][iPlace1] = energy;
				}
			}

		}

		cin >> cPosMe >> cPosRev;

		iPosMe = (int)cPosMe-65;
		iPosRev = (int)cPosRev-65;



		vector<int> dis1 = dijk(iPosMe, adjMe);
		vector<int> dis2 = dijk(iPosRev, adjRev);


		int min = inf;
		char c;

		for (int i=0; i<dis1.size(); i++) {
			if (dis1.at(i) == inf || dis2.at(i) == inf)
				continue;
			if (dis1.at(i) + dis2.at(i) < min) {
				min = dis1.at(i) + dis2.at(i);
			}
		}

    if (min == inf) {
			cout << "You will never meet." << endl;
      continue;
		}

    cout << min;
    for (int i=0; i<dis1.size(); i++) {
			if (dis1.at(i) + dis2.at(i) == min) {
				c = (char)i + 65;
        cout << " " << c;
			}
		}

    cout << endl;

	}
	return 0;
}

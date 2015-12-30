#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define cn 20
#define inf 32767

using namespace std;

int backtracking(vector<int> path, vector<vector<int>> ady, vector<vector<int>> paths, int goal) {
  int ultimo = path.back();
  int count = 0;

  if (ultimo == goal) {
    cout << path.at(0)+1;
    for (int i=1; i<path.size(); i++) {
      cout << " " << path.at(i)+1;
    }
    cout << endl;
    return 1;
  }

  for (int i=1; i<cn; i++) {
    cout << i << endl;
    if (find(path.begin(), path.end(), i) == path.end()) {
      if (paths[ultimo][i] < inf && ady[ultimo][i] == 1) {
        path.push_back(i);
        count += backtracking(path, ady, paths, goal);
        path.pop_back();
      }
    }
  }

  return count;
}


int main() {
	ios_base::sync_with_stdio (false);
	int goal;
  int a, b;
  int nums;
  int cases = 1;

  while (cin >> goal) {

    cout << "CASE " << cases << ":" << endl;

    vector<vector<int>> ady;
    for (int i=0; i<cn; i++) {
      vector<int> temp;
      for (int j=0; j<cn; j++) {
        temp.push_back(inf);
      }
      ady.push_back(temp);
    }
    while (cin >> a >> b && a && b) {
      ady[a-1][b-1] = 1;
      ady[b-1][a-1] = 1;
    }


    vector<vector<int>> paths;
    paths = ady;

    for (int i=0; i<cn; i++)
      paths[i][i] = 0;

    for (int k=0; k<cn; k++)
      for (int i=0; i<cn; i++)
        for (int j=0; j<cn; j++) {
          int dt = paths[i][k] + paths[k][j];
          if (paths[i][j] > dt)
            paths[i][j] = dt;
        }

    vector<int> path;
    path.push_back(0);
    nums = backtracking(path, ady, paths, goal-1);

    cout << "There are " << nums << " routes from the firestation to streetcorner " << goal << "." << endl;
    cases++;
  }

	return 0;
}

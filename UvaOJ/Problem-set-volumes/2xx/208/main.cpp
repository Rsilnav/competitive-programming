#include <iostream>

using namespace std;

bool canVisit[21];
bool matrix[21][21];
int counter;
int cases = 1;

void buscarCaminos(string path, int n, int destination, int v, int maxim) {
  if (canVisit[n]) {
    if (n == destination) {
      counter++;
      cout << path << endl;
    }
    else {
      for (int i=1; i<=maxim; i++) {
        if ((v & (1 << i)) == 0 && matrix[n][i]) {
          buscarCaminos(path + " " + to_string(i), i, destination, v | (1 << i), maxim);
        }
      }
    }
  }
}

void dfs(int n, int maxim) {
  canVisit[n] = true;
  for (int i=1; i<=maxim; i++)
    if (matrix[n][i] && !canVisit[i])
      dfs(i, maxim);
}

int main() {
	ios_base::sync_with_stdio (false);
	int destination, maxim, x, y;
  while (cin >> destination) {

    for (int i=0; i<21; i++) {
      for (int j=0; j<21; j++)
        matrix[i][j] = false;
      canVisit[i] = false;
    }
    maxim = 0;
    counter = 0;

    while (cin >> x >> y && x && y) {
      matrix[x][y] = true;
      matrix[y][x] = true;
      maxim = max(max(x, y), maxim);
    }

    dfs(destination, maxim);
    cout << "CASE " << cases++ << ":\n";
    buscarCaminos("1", 1, destination, 2, maxim);
    cout << "There are " << counter << " routes from the firestation to streetcorner " << destination << "." << endl;


  }
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int x, y;
  int maxim;
  int opt1, opt2, opt3;
  int cases = 1;
  while (cin >> x >> y && x && y) {
    int mx[x];
    int my[y];

    for (int i=0; i<x; i++)
      cin >> mx[i];
    for (int i=0; i<y; i++)
      cin >> my[i];

    int matrix[x+1][y+1];

    for (int i=0; i<y+1; i++) {
      matrix[0][i] = 0;
    }

    for (int i=0; i<x+1; i++) {
      matrix[i][0] = 0;
    }

    for (int i=1; i<x+1; i++) {
      for (int j=1; j<y+1; j++) {
        opt1 = matrix[i-1][j-1];
        opt2 = matrix[i-1][j];
        opt3 = matrix[i][j-1];
        if (mx[i-1] == my[j-1]) {
          opt1 += 1;
        }
        matrix[i][j] = max(opt1, max(opt2, opt3));
      }
    }
    cout << "Twin Towers #" << cases++ << endl;
    cout << "Number of Tiles : " << matrix[x][y] << endl << endl;
  }
	return 0;
}

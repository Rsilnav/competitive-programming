#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int tam, n;
  int cases = 1;
  int sum;
  while (cin >> tam && tam) {
    int m[tam][tam];
    for (int i=0; i<tam; i++) {
      for (int j=0; j<tam; j++) {
        cin >> m[i][j];
      }
    }

    int circles = (tam+1)/2;

    long sums[circles];

    cout << "Case " << cases << ":";

    for (int rad=0; rad<circles; rad++) {
      sum = 0;
      for (int i=rad; i<tam-rad; i++) {
        for (int j=rad; j<tam-rad; j++) {
          sum += m[i][j];
        }
      }
      sums[rad-1] -= sum;
      sums[rad] = sum;
    }

    for (int i=0; i<circles; i++) {
      cout << " " << sums[i];
    }
    cout << endl;
    cases++;

  }
	return 0;
}

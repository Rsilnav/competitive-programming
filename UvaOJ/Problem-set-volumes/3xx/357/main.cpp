#include <iostream>
#define maxChange 30000
#define numChanges 5

using namespace std;

int change[numChanges] = {1, 5, 10, 25, 50};
long m[numChanges][maxChange+1];

void init() {
  long x;
  for (int i=0; i<numChanges; i++) {
    for (int j=0; j<=maxChange; j++) {
      x = 0;
      if (j==0) {
        x = 1;
      }
      else {
        if (change[i] <= j)
          x += m[i][j-change[i]];
        if (i>0)
          x += m[i-1][j];
      }
      m[i][j] = x;
    }
  }
}

void print() {
  for (int i=0; i<numChanges; i++) {
    for (int j=0; j<=10; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
	ios_base::sync_with_stdio (false);
	int money;
  init();
  //print();
  while (cin >> money) {
    if (m[numChanges-1][money] == 1)
      cout << "There is only 1 way to produce " << money << " cents change." << endl;
    else
      cout << "There are " << m[numChanges-1][money] << " ways to produce " << money << " cents change." << endl;
  }
	return 0;
}

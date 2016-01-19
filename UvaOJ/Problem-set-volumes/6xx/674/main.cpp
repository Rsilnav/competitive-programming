#include <iostream>
#define maxChange 7489
#define numChanges 5

using namespace std;

int change[numChanges] = {1, 5, 10, 25, 50};
int m[numChanges][maxChange+1];

void init() {
  int x;
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
    cout << m[numChanges-1][money] << endl;
  }
	return 0;
}

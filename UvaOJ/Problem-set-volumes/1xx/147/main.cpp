#include <iostream>
#define maxChange 300000
#define numChanges 11

using namespace std;

unsigned long change[numChanges] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
unsigned long m[numChanges][maxChange+1];

void init() {
  unsigned long x;
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
  int note, coin;
  string num;
  init();
  //print();
  while (scanf("%d.%d", &note, &coin) && (note || coin)) {
    num = to_string(note) + ".";
    if (coin < 10)
      num += "0";
    num += to_string(coin);
    printf("%6s%17lu\n", num.c_str(), m[numChanges-1][note*100+coin]);
  }
	return 0;
}

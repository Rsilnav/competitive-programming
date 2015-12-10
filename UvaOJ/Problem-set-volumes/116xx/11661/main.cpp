#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio (false);

  int places;
  int minimum;
  char c;
  int pointerR, pointerD;
  while (cin >> places && places) {
    minimum = places;
    pointerR = -1*places;
    pointerD = -1*places;

    for (int i=0; i<places; i++) {
      cin >> c;
      if (c=='Z') {
        minimum = 0;
      }
      else if (c=='R') {
        if (i-pointerD < minimum) {
          minimum = i-pointerD;
        }
        pointerR = i;
      }
      else if (c=='D') {
        if (i-pointerR < minimum) {
          minimum = i-pointerR;
        }
        pointerD = i;
      }

    }

    cout << minimum << endl;
  }

  return 0;
}

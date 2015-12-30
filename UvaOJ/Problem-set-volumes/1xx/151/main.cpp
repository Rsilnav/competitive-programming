#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int a, count, pointer, added;
  while (cin >> a && a) {
    int m = 1;
    while (true) {
      count = 1;
      pointer = 0;
      bool zonas[a];
      for (int i=0; i<a; i++) zonas[i] = false;
      added = 0;

      zonas[pointer] = true;

      while (count < a) {
        pointer++;

        if (pointer >= a) {
          pointer = 0;
        }

        if (!zonas[pointer]) {
          added++;
        }

        if (added == m) {
          added = 0;
          zonas[pointer] = true;
          count++;
        }
      }

      if (pointer == 12) {
        cout << m << endl;
        break;
      }
      m++;
    }
  }
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long int k, m;
  int count;
  float x;
  string r;
  while (cin >> k >> m) {
    if (k < 2 || m < 2 || k < m) {
      r = "Boring!";
    }
    else {
      r = "";
      while (k != 1) {
        r = r + to_string(k);
        if (k % m == 0) {
          k = k / m;
        }
        else {
          r = "Boring!";
          break;
        }
        r += " ";
        if (k == 1) {
          r += "1";
          break;
        }
      }
    }
    cout << r << endl;
  }
  return 0;
}

#include <iostream>

using namespace std;

int main() {

  int cases;
  cin >> cases;
  int count;
  int digits;
  string s1, s2;
  int a, b, m, n;

  for (int i=0; i<cases; i++) {
    count = 0;
    cin >> digits;
    cin >> s1 >> s2;

    for (int j=0; j<digits; j++) {
      a = s1.at(j)-48;
      b = s2.at(j)-48;
      if (a > b) {
        m = a;
        n = b;
      }
      else {
        m = b;
        n = a;
      }
      count = count + min(m-n, 10+n-m);
    }

    cout << "Case " << i+1 << ": " << count << endl;
  }


  return 0;
}

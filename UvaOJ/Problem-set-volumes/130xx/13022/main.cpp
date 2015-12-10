#include <iostream>

using namespace std;

int main() {
  long long a, b;
  long long count, t;
  long long n = 0LL, m = 0LL;

  long long module;

  while (cin >> a >> b) {
    count = 0LL;
    for (long long i=a; i<b; i++) {
      t = i;
      while (t > 0) {
        module = t%2;

        if (module == 0 && n == 0) {
          break;
        }

        t /= 2;
        count++;

      }


    }

    cout << count << endl;
  }
  return 0;
}

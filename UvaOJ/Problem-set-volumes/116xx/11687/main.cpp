#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio (false);

  string s;
  int count;
  while (getline(cin, s) && s != "END") {
    count = 1;
    while (s != "1") {
      s = to_string(s.size());
      count++;
    }
    cout << count << endl;
  }

  return 0;
}

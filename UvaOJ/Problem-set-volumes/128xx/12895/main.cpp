#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
  cin >> cases;
  string s;
  int order;
  long n;
  bool itis;
  for (int i=0; i<cases; i++) {
    cin >> s;
    order = 1;
    itis = false;
    n = 0;
    while (n < stoi(s)) {
      n = 0;
      for (int j=0; j<s.size(); j++) {
        n += pow((int)(s.at(j)-48), order);
      }
      if (stoi(s) == n) {
        itis = true;
        break;
      }
      order++;
    }
    if (itis) {
      cout << "Armstrong" << endl;
    }
    else {
      cout << "Not Armstrong" << endl;
    }
  }
	return 0;
}

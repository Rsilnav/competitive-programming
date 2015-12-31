#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
  string s1, s2;
  string t1, t2;
  cin >> cases;
  for (int i=0; i<cases; i++) {
    t1 = "";
    t2 = "";
    cin >> s1;
    cin >> s2;
    for (int j=0; j<s1.size(); j++) {
      if (s1.at(j) == 'a' || s1.at(j) == 'e' || s1.at(j) == 'i' || s1.at(j) == 'o' || s1.at(j) == 'u') {

      }
      else {
        t1 = t1 + s1.at(j);
      }
    }
    for (int j=0; j<s2.size(); j++) {
      if (s2.at(j) == 'a' || s2.at(j) == 'e' || s2.at(j) == 'i' || s2.at(j) == 'o' || s2.at(j) == 'u') {

      }
      else {
        t2 = t2 + s2.at(j);
      }
    }
    if (t1 == t2) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
	return 0;
}

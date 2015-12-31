#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
  cin >> cases;
  cin.ignore();
  string s;
  string r;
  for (int i=0; i<cases; i++) {
    if (i != 0) {
      cout << endl;
    }
    while (getline(cin, s) && s != "") {
      r = "";
      for (int j=0; j<s.size(); j++) {
        if (s.at(j) == '3') {
          r += 'E';
        }
        else if (s.at(j) == '0') {
          r += 'O';
        }
        else if (s.at(j) == '1') {
          r += 'I';
        }
        else if (s.at(j) == '8') {
          r += 'B';
        }
        else if (s.at(j) == '5') {
          r += 'S';
        }
        else if (s.at(j) == '7') {
          r += 'T';
        }
        else if (s.at(j) == '2') {
          r += 'Z';
        }
        else if (s.at(j) == '4') {
          r += 'A';
        }
        else if (s.at(j) == '6') {
          r += 'G';
        }
        else if (s.at(j) == '9') {
          r += 'P';
        }
        else {
          r += s.at(j);
        }
      }
      cout << r << endl;
    }
  }
	return 0;
}

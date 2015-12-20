#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  string inp;
  char c;
  int maxim, partial;
  bool set;
  bool simple;
  for (int i=0; i<cases; i++) {
    cin >> inp;
    maxim = -1;

    for (int j=0; j<inp.size(); j++) {
      c = inp.at(j);
      set = false;

      if (c == '<') {
        partial = 1;
        for (int k=j+1; k<inp.size(); k++) {
          if (inp.at(k) == '=') {
            if (set && !simple) {
              partial++;
            }
            else if (set && simple) {
              break;
            }
            else if (!set) {
              set = true;
              simple = false;
              partial++;
            }
          }
          else if (inp.at(k) == '-') {
            if (set && !simple) {
              break;
            }
            else if (set && simple) {
              partial++;
            }
            else if (!set) {
              set = true;
              simple = true;
              partial++;
            }
          }
          else {
            break;
          }
        }
        if (partial > maxim) maxim = partial;
      }
      else if (c == '>') {
        partial = 1;
        for (int k=j-1; k>=0; k--) {
          if (inp.at(k) == '=') {
            if (set && !simple) {
              partial++;
            }
            else if (set && simple) {
              break;
            }
            else if (!set) {
              set = true;
              simple = false;
              partial++;
            }
          }
          else if (inp.at(k) == '-') {
            if (set && !simple) {
              break;
            }
            else if (set && simple) {
              partial++;
            }
            else if (!set) {
              set = true;
              simple = true;
              partial++;
            }
          }
          else {
            break;
          }
        }
        if (partial > maxim) maxim = partial;
      }
    }
    cout << "Case " << i+1 << ": " << maxim << endl;
  }
  return 0;
}

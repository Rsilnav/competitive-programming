#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  int cases;
  cin >> cases;

  int L, R, S;
  set<int> sL;
  set<int> sR;
  set<int> sS;
  int num;

  int n, x;

  for (int i=0; i<cases; i++) {
    int uniques[3] = {0};
    int dontHave[3] = {0};
    cout << "Case #" << i+1 << ":\n";
    cin >> L >> R >> S;

    for (int j=0; j<L; j++) {
      cin >> num;
      sL.insert(num);
    }
    for (int j=0; j<R; j++) {
      cin >> num;
      sR.insert(num);
    }
    for (int j=0; j<S; j++) {
      cin >> num;
      sS.insert(num);
    }

    for (set<int>::iterator it=sL.begin(); it!=sL.end(); ++it) {
      n = *it;
      if (sR.find(n) == sR.end() && sS.find(n) == sS.end()) {
        uniques[0]++;
      }
      else if (sR.find(n) == sR.end()) {
        dontHave[1]++;
      }
      else if (sS.find(n) == sS.end()) {
        dontHave[2]++;
      }
      else {
      }
    }

    for (set<int>::iterator it=sR.begin(); it!=sR.end(); ++it) {
      n = *it;
      if (sL.find(n) == sL.end() && sS.find(n) == sS.end()) {
        uniques[1]++;
      }
      else if (sL.find(n) == sL.end()) {
        dontHave[0]++;
      }
      else if (sS.find(n) == sS.end()) {
        dontHave[2]++;
      }
      else {
      }
    }

    for (set<int>::iterator it=sS.begin(); it!=sS.end(); ++it) {
      n = *it;
      if (sL.find(n) == sL.end() && sR.find(n) == sR.end()) {
        uniques[2]++;
      }
      else if (sL.find(n) == sL.end()) {
        dontHave[0]++;
      }
      else if (sR.find(n) == sR.end()) {
        dontHave[1]++;
      }
      else {
      }
    }

    for (int j=0; j<3; j++) {
      cout << uniques[j] << " " << dontHave[j]/2 << endl;
    }
    sL.clear();
    sR.clear();
    sS.clear();
  }

  return 0;
}

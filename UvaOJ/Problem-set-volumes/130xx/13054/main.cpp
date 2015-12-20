#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio (false);
  int cases;
  cin >> cases;
  unsigned long int n, h, ta, td;
  vector<unsigned long int> hipos;
  unsigned long int hipo;
  unsigned long int timeSpent;
  unsigned long int p1, p2;
  int c;

  for (int i=0; i<cases; i++) {
    cin >> n >> h >> ta >> td;
    timeSpent = 0;

    for (int j=0; j<n; j++) {
      cin >> hipo;
      hipos.push_back(hipo);
    }

    if (td >= ta*2) {
      cout << "Case " << i+1 << ": " << ta*n << endl;
      hipos.clear();
      continue;
    }

    sort(hipos.begin(), hipos.end());

    int t[hipos.size()];
    c = 0;
    for (vector<unsigned long int>::iterator it=hipos.begin(); it!=hipos.end(); ++it) {
      t[c] = *it;
      c++;
    }

    p1 = 0;
    p2 = n-1;

    while (p2 >= p1) {
      if (p1 != p2 && t[p1]+t[p2] < h) {
        timeSpent += td;
        p1++;
      }
      else {
        timeSpent += ta;
      }
      p2--;
    }

    cout << "Case " << i+1 << ": " << timeSpent << endl;
    hipos.clear();
  }

  return 0;
}

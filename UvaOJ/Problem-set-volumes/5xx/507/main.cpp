#include <iostream>

using namespace std;

int t[20001];

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
  cin >> cases;
  int num;
  for (int i=1; i<=cases; i++) {
    cin >> num;
    t[0] = 0;
    for (int j=1; j<num; j++) {
      cin >> t[j];
    }

    int maxim = 0;
    int local = 0;
    int mA, mB;
    int lA=0, lB=0;

    for (int j=1; j<num; j++) {
      local += t[j];

      if (local > maxim || (local==maxim && j-lA > mB-mA)) {
        mB = j;
        mA = lA;
        maxim = local;
      }

      if (local < 0) {
        local = 0;
        lA = j;
      }
    }

    if (maxim <= 0)
      cout << "Route " << i << " has no nice parts" << endl;
    else
      cout << "The nicest part of route " << i << " is between stops " << mA+1 << " and " << mB+1 << endl;

  }
	return 0;
}

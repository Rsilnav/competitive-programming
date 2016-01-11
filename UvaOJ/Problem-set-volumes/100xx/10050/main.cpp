#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
  cin >> cases;
  int days, parties, party, count;
  for (int i=0; i<cases; i++) {
    cin >> days;
    bool d[days];

    for (int j=0; j<days; j++) {
      d[j] = false;
    }

    cin >> parties;
    for (int j=0; j<parties; j++) {
      cin >> party;
      for (int k=0; k<days; k++) {
        if (k%7==5 || k%7==6) {
          continue;
        }
        else {
          if ((k+1)%party==0) {
            d[k] = true;
          }
        }
      }
    }

    count = 0;
    for (int j=0; j<days; j++) {
      if (d[j])
        count++;
    }
    cout << count << endl;
  }
	return 0;
}

#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;

  string street;
  int positions;
  char pos;

  for (int i=0; i<cases; i++) {
    cin >> street;
    bool posible[street.size()];
    positions = 0;
    for (int j=0; j<street.size(); j++) posible[j] = true;

    for (int j=0; j<street.size(); j++) {
      pos = street.at(j);
      if (pos == 'D') {
        posible[j] = false;
      }
      else if (pos == 'B') {
        posible[j] = false;
        if (j>=2) {
          posible[j-2] = false;
        }
        if (j>=1) {
          posible[j-1] = false;
        }
      }
      else if (pos == 'S') {
        posible[j] = false;
        if (j>=1) {
          posible[j-1] = false;
        }
        if (j<street.size()-1) {
          posible[j+1] = false;
        }
      }
    }

    for (int j=0; j<street.size(); j++) {
      if (posible[j]) positions++;
    }

    cout << "Case " << i+1 << ": " << positions << endl;
  }



  return 0;
}

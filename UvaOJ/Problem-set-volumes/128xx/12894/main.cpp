#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
  cin >> cases;
  double x0, y0, x1, y1, cx, cy, r;
  bool valid;
  for (int i=0; i<cases; i++) {
    cin >> x0 >> y0 >> x1 >> y1 >> cx >> cy >> r;
    valid = true;

    if (6*(x1-x0)/10 != (y1-y0)) {
      valid = false;
    }

    if ((x1-x0)/5 != r) {
      valid = false;
    }

    if ((y1+y0)/2 != cy) {
      valid = false;
    }

    if (9*(x1-x0)/20 != cx-x0) {
      //cout << x1 << " " << x0 << " " << cx-x0 << endl;
      valid = false;
    }

    if (valid) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
	return 0;
}

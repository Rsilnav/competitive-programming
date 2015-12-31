#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases, x, y, r;
  cin >> cases;
  for (int i=0; i<cases; i++) {
    cin >> x >> y >> r;
    float maxim = sqrt(x*x + y*y) + r;
    float minim = r - sqrt(x*x + y*y);
    printf("%.2f %.2f\n", minim, maxim);
  }
	return 0;
}

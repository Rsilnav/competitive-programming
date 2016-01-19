#include <iostream>
#include <cmath>

using namespace std;

long memo[1000001];

long calc(long t) {
  if (t==0) {
    return 1;
  }
  else if (memo[t] != -1) {
    return memo[t];
  }
  else {
    memo[t] = (calc(floor(t-sqrt(t))) + calc(floor(log(t))) + calc(floor(t*sin(t)*sin(t))))%1000000;
    return memo[t];
  }
}

int main() {
	ios_base::sync_with_stdio (false);
  for (int i=0; i<1000001; i++) memo[i] = -1;
	long x;
  while (cin >> x && x >= 0) {
    cout << calc(x) << endl;
  }
	return 0;
}

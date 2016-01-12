#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
  int cases;
  long taxes, money;
  cin >> cases;
  for (int i=1; i<=cases; i++) {
    taxes = 0;
    cin >> money;
    if (money > 180000) taxes += 10 * (min(money, 480000)-180000);
    if (money > 480000) taxes += 15 * (min(money, 880000)-480000);
    if (money > 880000) taxes += 20 * (min(money, 1180000)-880000);
    if (money > 1180000) taxes += 25 * (money-1180000);
    if (taxes > 0) taxes = max(taxes, 200000);
    taxes = taxes/100 + (taxes%100!=0);
    cout << "Case " << i << ": " << taxes << endl;
  }
	return 0;
}

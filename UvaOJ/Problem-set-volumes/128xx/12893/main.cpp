#include <iostream>
using namespace std;
int main() {
  int cas,count;
  long long int n;
  cin >> cas;
  while(cas--) {
    count = 0;
    cin >> n;
    do {
      count+=n&1;
    } while(n/=2);
    cout << count << endl;
  }
  return 0;
}

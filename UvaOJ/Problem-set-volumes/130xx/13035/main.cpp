#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  unsigned long int n;
  unsigned long int n1;
  unsigned long int n2;

  unsigned long int n3;


  unsigned long int x;
  for (unsigned long int i=0; i<cases;i++) {
    cin >> n;
    n1 = n+1;
    n2 = n+2;
    if (n%3==0) n=n/3;
    else if (n1%3==0) n1=n1/3;
    else if (n2%3==0) n2=n2/3;

    n3 = (n*n1)%1000000007;
    n3 = (n3*n2)%1000000007;
    cout << "Case " << i+1 << ": " << n3 << endl;

    //x = (n*(n+1)*(n+2)/3)%1000000007;
  }

  return 0;
}

#include <iostream>

using namespace std;

int pointer1;
int pointer2;
char c1, c2;
int i1, i2, suma;
int acarreo;

string sumStrings(string a, string b) {
  string res = "";

  pointer1 = a.size()-1;
  pointer2 = b.size()-1;
  acarreo = 0;

  while (pointer1 >= 0 || pointer2 >= 0) {
    i1 = 0;
    if (pointer1 >= 0) {
      c1 = a.at(pointer1);
      i1 = (int)c1 - 48;
      pointer1--;
    }
    i2 = 0;
    if (pointer2 >= 0) {
      c2 = b.at(pointer2);
      i2 = (int)c2 - 48;
      pointer2--;
    }
    suma = i1+i2+acarreo;
    acarreo = suma/10;
    suma = suma%10;
    res = char(suma+48) + res;
  }
  if (acarreo > 0) {
    res = char(acarreo+48) + res;
  }
  return res;
}


int main() {
  ios_base::sync_with_stdio (false);

  string fib[5001];
  fib[0] = "0";
  fib[1] = "1";

  for (int i=2; i<5001; i++) {
    fib[i] = sumStrings(fib[i-2], fib[i-1]);
  }

  int num;
  while (cin >> num) {
    cout << "The Fibonacci number for " << num << " is " << fib[num] << "\n";
  }

  return 0;
}

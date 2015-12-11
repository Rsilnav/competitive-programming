#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long x) {
  if (x==0 || x==1) return false;
  if (x%2==0) return false;
  long root = sqrt(x);
  for (int i=2; i<=root; i++) {
    if (x%i==0) {
      return false;
    }
  }
  return true;
}

vector<long> primes;

int main() {
  ios_base::sync_with_stdio (false);
  long entrada;

  primes.push_back(3);
  primes.push_back(5);

  long x = (500000-5)/6;
  for (long i=1; i<x; i++) {
    if (isPrime(6*i+1))
      primes.push_back(6*i+1);
    if (isPrime(6*i+5))
      primes.push_back(6*i+5);
  }

  while (cin >> entrada && entrada) {
    for (int i=0; i<primes.size(); i++) {
      if (isPrime(entrada-primes.at(i))) {
        cout << entrada << " = " << primes.at(i) << " + " << entrada-primes.at(i) << endl;
        break;
      }
    }
  }

  return 0;
}

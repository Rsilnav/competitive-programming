#include <iostream>

using namespace std;

int main() {

  int cases, num;
  bool solved;
  cin >> cases;

  for (int i=0; i<cases; i++) {
    solved = true;
    for (int j=0; j<13; j++) {
      cin >> num;
      if (num == 0) {
        solved = false;
      }
    }
    if (solved) {
      cout << "Set #" << i+1 << ": Yes\n";
    }
    else {
      cout << "Set #" << i+1 << ": No\n";
    }
  }



  return 0;
}

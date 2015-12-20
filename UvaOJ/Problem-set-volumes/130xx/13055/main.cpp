#include <iostream>
#include <stack>

using namespace std;

int main() {

  string inp;
  int cases;
  cin >> cases;

  stack<string> dreams;

  for (int i=0; i<cases; i++) {

    cin >> inp;

    if (inp == "Sleep") {
      cin >> inp;
      dreams.push(inp);
    }
    else if (inp == "Test") {
      if (dreams.empty()) {
        cout << "Not in a dream" << endl;
      }
      else {
        cout << dreams.top() << endl;
      }
    }
    else if (inp == "Kick") {
      if (dreams.empty()) {

      }
      else {
        dreams.pop();
      }
    }


  }

  return 0;
}

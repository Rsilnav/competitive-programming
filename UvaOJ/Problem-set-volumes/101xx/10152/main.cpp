#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int cases, numTurtles, ini, fin;
    cin >> cases;
    string s;

    string turtles[200];
    string obj[200];

    string r = "";

    for (int i=0; i<cases; i++) {
      cin >> numTurtles;
      cin.ignore();
      for (int j=0; j<numTurtles; j++) {
        getline(cin, s);
        turtles[j] = s;
      }
      for (int j=0; j<numTurtles; j++) {
        getline(cin, s);
        obj[j] = s;
      }
      ini=numTurtles-1;
      fin=numTurtles-1;
      while (ini>=0) {
        if (turtles[ini] == obj[fin]) {
          fin--;
        }
        ini--;
      }
      for (int j=fin; j>=0; j--) {
        r+=obj[j]+"\n";
      }
      r+="\n";
    }
    cout << r;
    return 0;
}

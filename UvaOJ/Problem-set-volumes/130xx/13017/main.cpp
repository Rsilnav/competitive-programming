#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  long cuadro, temp, num_cuadros, res;
  priority_queue<long, vector<long>, greater<long>> cinta;

  for (int i=0; i<cases; i++) {
    cin >> num_cuadros;

    for (int j=0; j<num_cuadros; j++) {
      cin >> cuadro;
      cinta.push(cuadro);
    }

    res = 0;
    while (cinta.size() > 1) {
      temp = cinta.top();
      cinta.pop();
      temp += cinta.top();
      cinta.pop();
      res += temp;
      cinta.push(temp);
    }
    cout << res << endl;
    cinta.pop();
  }
  return 0;
}

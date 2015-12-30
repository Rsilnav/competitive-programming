#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int rows, cols;
  string s;

  while (cin >> rows >> cols && rows) {

    bool mapa[rows][cols];

    for (int i=0; i<rows; i++) {
      cin >> s;
      for (int j=0; j<cols; j++) {
        if (s.at(j) == '*') {
          mapa[i][j] = false;
        }
        else {
          mapa[i][j] = true;
        }
      }
    }

    int count = 0;
    stack<int> filas;
    stack<int> columnas;

    for (int i=0; i<rows; i++) {
      for (int j=0; j<cols; j++) {

        if (mapa[i][j]) {
          count++;
          filas.push(i);
          columnas.push(j);
          mapa[i][j] = false;

          while (!filas.empty()) {
            int f, c;
            f = filas.top();
            c = columnas.top();

            filas.pop();
            columnas.pop();

            for (int m=-1; m<=1; m++) {
              for (int n=-1; n<=1; n++) {
                if (m == 0 && n == 0) continue;
                if (f+m < 0 || f+m >= rows) continue;
                if (c+n < 0 || c+n >= cols) continue;
                if (mapa[f+m][c+n]) {
                  mapa[f+m][c+n] = false;
                  //cout << f+m << " " << c+n << " desactivada." << endl;
                  filas.push(f+m);
                  columnas.push(c+n);
                }
              }
            }

          }

        }

      }
    }


    cout << count << endl;

  }

	return 0;
}

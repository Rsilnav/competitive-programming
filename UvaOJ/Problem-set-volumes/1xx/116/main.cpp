#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

#define INF 32767

using namespace std;

int rows, cols, t, nextRow, del, minim, r, c;
vector<vector<int>> matrix, minimum;
vector<int> temp;
list<int> orders;

int main() {

  while (cin >> rows >> cols) {
    for (int i=0; i<rows; i++) {
      for (int j=0; j<cols; j++) {
        cin >> t;
        temp.push_back(t);
      }
      matrix.push_back(temp);
      temp.clear();
    }

    for (int i=0; i<cols; i++) {
      temp.push_back(INF);
    }
    for (int i=0; i<rows; i++) {
      minimum.push_back(temp);
    }
    temp.clear();

    for (int i=0; i<rows; i++) {
      minimum[i][cols-1] = matrix[i][cols-1];
    }

    for (int j=cols-2; j>=0; j--) {
      for (int i=0; i<rows; i++) {
        minim = INF;
        for (int k=-1; k<=1; k++) {
          del = (i+k+rows)%rows;
          if (minimum[del][j+1] < minim) {
            minim = minimum[del][j+1];
          }
        }
        minimum[i][j] = minim + matrix[i][j];
      }
    }

    minim = INF;
    for (int i=0; i<rows; i++) {
      if (minimum[i][0] < minim) {
        minim = minimum[i][0];
        r = i;
      }
    }

    c = 0;
    while (c != cols) {
      if (c>0)
        cout << " ";
      cout << r+1;

      for (int i=-1; i<= 1; i++) {
        orders.push_back((r+i+rows)%rows);
      }
      orders.sort();
      orders.unique();

      list<int>::iterator it;
      for (it=orders.begin(); it!=orders.end(); ++it) {
        nextRow = *it;
        if (minimum[r][c] == minimum[nextRow][c+1] + matrix[r][c]) {
          r = nextRow;
          break;
        }
      }
      c++;
      orders.clear();
    }

    cout << endl;

    cout << minim << endl;

    temp.clear();
    minimum.clear();
    matrix.clear();
  }

  return 0;
}

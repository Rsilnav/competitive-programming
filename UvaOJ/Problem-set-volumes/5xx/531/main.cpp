#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s1, s2;
  int t1, t2;
  int opt1, opt2, opt3;
  bool flag;
  string temp;
  string words1[100];
  string words2[100];

  while (cin >> temp) {
    t1 = 0;
    t2 = 0;
    words1[t1++] = temp;
    while (cin >> temp && temp != "#") {
      words1[t1++] = temp;
    }
    while (cin >> temp && temp != "#") {
      words2[t2++] = temp;
    }

    int matrix[t1+1][t2+1];
    string matrixs[t1+1][t2+1];

    for (int i=0; i<t2+1; i++) {
      matrix[0][i] = 0;
      matrixs[0][i] = "";
    }


    for (int i=0; i<t1+1; i++) {
      matrix[i][0] = 0;
      matrixs[i][0] = "";
    }

    for (int i=1; i<t1+1; i++) {
      for (int j=1; j<t2+1; j++) {
        opt1 = matrix[i-1][j-1];
        opt2 = matrix[i-1][j];
        opt3 = matrix[i][j-1];
        flag = false;
        if (words1[i-1] == words2[j-1]) {
          opt1++;
          flag = true;
        }
        if (opt1 >= opt2 && opt1 >= opt3) {
          matrix[i][j] = opt1;
          if (flag)
            matrixs[i][j] = matrixs[i-1][j-1] + " " + words1[i-1];
          else
            matrixs[i][j] = matrixs[i-1][j-1];
        }
        else if (opt2 >= opt3){
          matrix[i][j] = opt2;
          matrixs[i][j] = matrixs[i-1][j];
        }
        else {
          matrix[i][j] = opt3;
          matrixs[i][j] = matrixs[i][j-1];
        }

      }
    }

    cout << matrixs[t1][t2].substr(1, matrixs[t1][t2].size()) << endl;
  }
  return 0;
}

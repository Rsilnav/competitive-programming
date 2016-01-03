#include <iostream>

using namespace std;

int score(char c1, char c2) {
  if (c1 == c2)
    return 0;
  return 1;
}

int main() {
	ios_base::sync_with_stdio (false);
	string s1, s2;
  int t1, t2;
  int maxim;
  int opt1, opt2, opt3;
  while (cin >> t1 >> s1 >> t2 >> s2) {
    int matrix[t1+1][t2+1];

    matrix[0][0] = 0;
    for (int i=1; i<t2+1; i++)
      matrix[0][i] = i * score(' ', s2.at(i-1));
    for (int i=1; i<t1+1; i++)
      matrix[i][0] = i * score(' ', s1.at(i-1));


    for (int i=1; i<t1+1; i++) {
      for (int j=1; j<t2+1; j++) {
        opt1 = matrix[i-1][j-1];
        opt2 = matrix[i-1][j]+1;
        opt3 = matrix[i][j-1]+1;
        if (s1[i-1] != s2[j-1]) {
          opt1 += 1;
        }
        matrix[i][j] = min(opt1, min(opt2, opt3));
      }
    }

    cout << matrix[t1][t2] << endl;
  }
	return 0;
}

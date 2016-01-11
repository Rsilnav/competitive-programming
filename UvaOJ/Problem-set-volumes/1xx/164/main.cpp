#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s1, s2;
  int t1, t2;
  int maxim;
  int opt1, opt2, opt3;
  bool flag;
  while (cin >> s1 && s1 != "#") {
		cin >> s2;
    t1 = s1.size();
    t2 = s2.size();
    int matrix[t1+1][t2+1];
    string matrixs[t1+1][t2+2];
    string r;
    for (int i=0; i<t2+1; i++) {
      matrix[0][i] = i;
    }

    for (int i=0; i<t1+1; i++) {
      matrix[i][0] = i;
    }

    for (int i=1; i<t1+1; i++) {
      for (int j=1; j<t2+1; j++) {
        opt1 = matrix[i-1][j-1];
        opt2 = matrix[i-1][j]+1;
        opt3 = matrix[i][j-1]+1;
        flag = false;
        if (s1[i-1] != s2[j-1]) {
          opt1++;
        }
        matrix[i][j] = min(opt1, min(opt2, opt3));
      }
    }

    for (int i=0; i<t1+1; i++) {
      for (int j=0; j<t2+1; j++) {
        cout << matrix[i][j];
      }
      cout << endl;
    }

    string r1="", r2="";
    int i, j;
    i = t1;
    j = t2;
    int score, scorediag, scoreup, scoreleft;
    while (i>0 && j>0) {
      score = matrix[i][j];
      scorediag = matrix[i-1][j-1];
      if (s1[i] != s2[j])
        scorediag++;
      scoreleft = matrix[i][j-1];
      scoreup = matrix[i-1][j];
      if (score == scorediag) {
        r1 = s1[i-1] + r1;
        r2 = s2[j-1] + r2;
        i--;
        j--;
      }
      else if (score == scoreleft) {
        r1 = s1[i-1] + r1;
        r2 = "-" + r2;
        i--;
      }
      else {
        r1 = "-" + r1;
        r2 = s2[j-1] + r2;
        j--;
      }
    }
    while (i>0) {
      r1 = s1[i-1] + r1;
      r2 = "-" + r2;
      i--;
    }
    while (j>0) {
      r1 = "-" + r1;
      r2 = s2[j-1] + r2;
      j--;
    }

    cout << matrix[t1][t2] << "E" << endl;
    cout << r1 << endl << r2 << endl;
  }
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s1, s2;
  int t1, t2;
  int maxim;
  int opt1, opt2, opt3;
  int cases = 1;
  while (getline(cin, s1) && s1 != "#") {
		getline(cin, s2);
    t1 = s1.size();
    t2 = s2.size();
    int matrix[t1+1][t2+1];

    for (int i=0; i<t2+1; i++) {
      matrix[0][i] = 0;
    }

    for (int i=0; i<t1+1; i++) {
      matrix[i][0] = 0;
    }

    for (int i=1; i<t1+1; i++) {
      for (int j=1; j<t2+1; j++) {
        opt1 = matrix[i-1][j-1];
        opt2 = matrix[i-1][j];
        opt3 = matrix[i][j-1];
        if (s1[i-1] == s2[j-1]) {
          opt1 += 1;
        }
        matrix[i][j] = max(opt1, max(opt2, opt3));
      }
    }

    cout << "Case #" << cases++ << ": you can visit at most " << matrix[t1][t2] << " cities." << endl;
  }
	return 0;
}

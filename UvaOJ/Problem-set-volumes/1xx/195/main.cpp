#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int CharToInt(char c) {
  int x = (int)c;
  if (x >= 65 && x <= 90) {
    return (x-65)*2;
  }
  else if (x >= 97 && x <= 122) {
    return (x-97)*2+1;
  }
}

char IntToChar(int i) {
  if (i%2==0) {
    return (char)(65+(i/2));
  }
  else {
    return (char)(97+(i/2));
  }
}

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
  cin >> cases;
  string s;
  for (int i=0; i<cases; i++) {
    cin >> s;

    vector<int> letras;
    for (int j=0; j<s.size(); j++) {
      letras.push_back(CharToInt(s.at(j)));
    }

    sort(letras.begin(), letras.end());

    do {
      for (int j=0; j<letras.size(); j++) {
        cout << IntToChar(letras.at(j));
      }
      cout << "\n";
    } while (next_permutation(letras.begin(), letras.end()));

  }
	return 0;
}

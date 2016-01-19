#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
  cin >> cases;
  string s;
  for (int i=0; i<cases; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    do {
      cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
    cout << endl;
  }

	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int correct, n, count;
  while (cin >> correct) {
    count = 0;
    for (int i=0; i<5; i++) {
      cin >> n;
      if (correct == n)
        count++;
    }
    cout << count << endl;
  }
	return 0;
}

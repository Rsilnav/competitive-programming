#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s;

	while (cin >> s && s.compare("#") != 0) {

		if (!next_permutation(s.begin(), s.end()))
			cout << "No Successor" << endl;
		else
			cout << s << endl;
	}
	return 0;
}

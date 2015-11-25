#include <iostream>

using namespace std;

int sky[10001] = {0};

int main() {
	ios_base::sync_with_stdio (false);

	string result = "";

	int x1, h, x2, max=0;
	while (cin >> x1 >> h >> x2) {
		for (int i=x1; i<x2; i++) {
			if (h > sky[i]) sky[i] = h;
		}
		if (x2 > max) max = x2;
	}

	for (int i=0; i<max+1; i++) {
		if (sky[i] != sky[i+1]) {
			if (result.size() > 1)
				result += " ";
			result += to_string(i+1) + " " + to_string(sky[i+1]);
		}
	}

	cout << result << endl;

	return 0;
}

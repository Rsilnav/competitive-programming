#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> streets;

int main() {
	ios_base::sync_with_stdio (false);
	int cases, relatives, med, distance, inp;
	cin >> cases;
	for (int i=0; i<cases; i++) {
		cin >> relatives;
		distance = 0;
		for (int j=0; j<relatives; j++) {
			cin >> inp;
			streets.push_back(inp);
		}
		nth_element(streets.begin(), streets.begin() + streets.size()/2, streets.end());
		med = streets[streets.size()/2];
		for (int j=0; j<relatives; j++) {
			if (med > streets[j])
				distance += (med - streets[j]);
			else
				distance += (streets[j] - med);
		}
		cout << distance << endl;
		streets.clear();
	}

	return 0;
}

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[100][100];
int inf = 32767;
int maxim;

void reset() {
	for (int i=0; i<100; i++) {
		for (int j=0; j<100; j++) {
			matrix[i][j] = inf;
		}
		matrix[i][i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio (false);
	int a, b;
	vector<int> nodes;

	int c = 0;

	while (cin >> a >> b && a != 0 && b != 0) {
		reset();
		nodes.push_back(a);
		nodes.push_back(b);
		c++;

		maxim = 0;

		matrix[a-1][b-1] = 1;
		if (a > maxim) maxim = a;
		if (b > maxim) maxim = b;

		while (cin >> a >> b && a != 0 && b != 0) {
			nodes.push_back(a);
			nodes.push_back(b);
			matrix[a-1][b-1] = 1;
			if (a > maxim) maxim = a;
			if (b > maxim) maxim = b;
		}

		for (int k=0; k<maxim; k++) {
			for (int i=0; i<maxim; i++) {
				for (int j=0; j<maxim; j++) {
					if (matrix[i][j] > matrix[i][k] + matrix[k][j])
						matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}

		double s = 0;
		for (int i=0; i<maxim; i++) {
			for (int j=0; j<maxim; j++) {
				if (matrix[i][j] != inf && matrix[i][j] != 0) {
					s += matrix[i][j];
				}
			}
		}

		sort( nodes.begin(), nodes.end() );
		nodes.erase( unique( nodes.begin(), nodes.end() ), nodes.end() );

		int l = nodes.size();
		s = s/(l*(l-1));
		printf("Case %d: average length between pages = %.3f clicks\n", c, s);
		nodes.clear();
	}

	return 0;
}

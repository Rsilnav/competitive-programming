#include <iostream>

using namespace std;

bool pierdeContra(char c1, char c2) {
	if (c1 == 'R' && c2 == 'P')
		return true;
	if (c1 == 'P' && c2 == 'S')
		return true;
	if (c1 == 'S' && c2 == 'R')
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	int r, c, n;

	string s;

	for (int i=0; i<cases; i++) {
		if (i > 0)
			cout << endl;

		cin >> r >> c >> n;
		cin.ignore();

		char matrix[r][c];

		for (int j=0; j<r; j++) {
			getline(cin, s);
			for (int k=0; k<c; k++) {
				matrix[j][k] = s.at(k);
			}
		}

		int temp[r][c];
		char actual;
		char sig;
		for (int j=0; j<n; j++) {
			for (int a=0; a<r; a++) {
				for (int b=0; b<c; b++) {
					actual = matrix[a][b];
					sig = actual;
					if (a-1 >= 0) {
						if (pierdeContra(actual, matrix[a-1][b]))
							sig = matrix[a-1][b];
					}
					if (a+1 < r) {
						if (pierdeContra(actual, matrix[a+1][b]))
							sig = matrix[a+1][b];
					}
					if (b-1 >= 0) {
						if (pierdeContra(actual, matrix[a][b-1]))
							sig = matrix[a][b-1];
					}
					if (b+1 < c) {
						if (pierdeContra(actual, matrix[a][b+1]))
							sig = matrix[a][b+1];
					}
					temp[a][b] = sig;
				}
			}

			for (int a=0; a<r; a++) {
				for (int b=0; b<c; b++) {
					matrix[a][b] = temp[a][b];
				}
			}
		}

		for (int a=0; a<r; a++) {
			for (int b=0; b<c; b++) {
				cout << matrix[a][b];
			}
			cout << endl;
		}

	}
	return 0;
}

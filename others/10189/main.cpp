#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int row, col;
	int cases = 1;
	while (cin >> row >> col) {
		if (row == 0 && col == 0)
			break;

		int campo[row][col];
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				campo[i][j] = 0;
			}
		}

		char c;
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				cin >> c;
				if (c == '*') {
					campo[i][j] = -1;
					for (int a=-1; a<=1; a++) {
						for (int b=-1; b<=1; b++) {
							if (0 <= i+a && i+a < row && 0 <= j+b && j+b < col) {
								if (campo[i+a][j+b] != -1) {
									campo[i+a][j+b]++;
								}
							}
						}
					}
				}
			}
		}
		if (cases > 1)
			cout << endl;
		cout << "Field #" << cases << ":" << endl;
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				if (campo[i][j] == -1) {
					cout << "*";
				}
				else {
					cout << campo[i][j];
				}
			}
			cout << endl;
		}
		cases++;
	}
	return 0;
}

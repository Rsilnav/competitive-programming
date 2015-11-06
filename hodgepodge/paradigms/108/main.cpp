#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int nums;
	cin >> nums;
	int matrix[nums][nums];
	int temp;
	for (int i=0; i<nums; i++) {
		for (int j=0; j<nums; j++) {
			cin >> temp;
			if (i>0)
				temp += matrix[i-1][j];
			if (j>0)
				temp += matrix[i][j-1];
			if (i>0 && j>0)
				temp -= matrix[i-1][j-1];
			matrix[i][j] = temp;
		}
	}

	int max = 0;
	int num;

	for (int i=0; i<nums; i++) {
		for (int j=0; j<nums; j++) {
			for (int x=i; x<nums; x++) {
				for (int y=j; y<nums; y++) {
					temp = matrix[x][y];

					if (i>0)
						temp -= matrix[i-1][y];
					if (j>0)
						temp -= matrix[x][j-1];
					if (i>0 && j>0)
						temp += matrix[i-1][j-1];

					if (temp > max)
						max = temp;
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int num;
	while (cin >> num) {
		if (num == 0)
			break;
		int temp;
		while(num > 9) {
			temp = 0;
			while (num > 9) {
				temp = temp + num%10;
				num = num / 10;
			}
			num = temp + num;
		}
		cout << num << endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	cin.ignore();
	string num;
	for (int i=0; i<cases; i++) {
		getline(cin, num);
		int tam = num.size();
		if (num == "1" or num == "4" or num == "78") {
			cout << "+" << endl;
		}
		else if (num[tam-2] == '3' and num[tam-1] == '5') {
			cout << "-" << endl;
		}
		else if (num[0] == '9' and num[tam-1] == '4') {
			cout << "*" << endl;
		}
		else if (num[0] == '1' and num[1] == '9' and num[2] == '0') {
			cout << "?" << endl;
		}
	}
	return 0;
}

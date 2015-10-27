#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string s;
	int count;
	bool isWord;
	int ascii;
	while (getline(cin, s)) {
		count = 0;
		isWord = false;
		for (int i=0; i<s.size(); i++) {
			ascii = (int)s.at(i);
			if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) {
				isWord = true;
			}
			else if (isWord) {
				count++;
				isWord = false;
			}
			if (i == s.size()-1 && isWord) {
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}

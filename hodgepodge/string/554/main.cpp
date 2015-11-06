#include <iostream>
#include <vector>

using namespace std;

int charToInt(char c) {
	if ((int)c == 32)
		return 0;
	return (int)c - 64;
}

char intToChar(int i) {
	if (i == 0)
		return ' ';
	return (char)i + 64;
}

int main() {
	ios_base::sync_with_stdio (false);
	vector<string> diccionario;
	string s;
	while (cin >> s) {
		if (s.compare("#") == 0)
			break;
		diccionario.push_back(s);
	}

	string phrase;
	string s2;
	int maxCount = 0;
	string better;
	int count;

	cin.ignore();
	getline(cin, phrase);
	size_t found;
	string word;

	for (int delay=0; delay<27; delay++) {
		count = 0;
		s2 = "";
		for (int i=0; i<phrase.size(); i++) {
			int num = charToInt(phrase.at(i));
			num += delay;
			num = num%27;
			s2 += intToChar(num);
		}

		for (int i=0; i<diccionario.size(); i++) {
			word = diccionario.at(i);
			found = s2.find(word);
			if (found != string::npos) {
				count++;
			}
		}

		if (count > maxCount) {
			maxCount = count;
			better = s2;
		}

	}

	int pointer = 0;
	int sum = 0;
	while (pointer < better.size()) {
		if (sum == 60 || pointer == better.size()-1) {
			while (better.at(pointer) != ' ') {
				pointer--;
			}
			better = better.substr(0, pointer) + "\n" + better.substr(pointer+1);
			pointer++;
			sum = 0;
		}

		pointer++;
		sum++;
	}
	cout << better;

	return 0;
}

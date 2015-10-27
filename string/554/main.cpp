#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string diccionario[100];
	char dic[100][20];
	string s;
	int i=0;
	while(getline(cin, s)) {
		if (s.compare("#") == 0)
			break;
		diccionario[i] = s;
		for (int x=0; x<s.size(); x++) {
			dic[i][x] = s.at(x);
		}
		cout << "Pillando palabra " << i << endl;
		i++;
	}

	int tamDic = i-1;

	string phrase;
	getline(cin, phrase);

	int maxWords = 0;
	int delay;
	int words;
	string w;



	for (int l=0; l<27; l++) {

		words = 0;

		for (int j=0; j<tamDic; j++) {
			w = string(dic[j]);
			if (phrase.find(w) != string::npos) {
				words++;
			}
		}

		if (words > maxWords) {
			delay = l;
			maxWords = words;
		}

		for (int j=0; j<tamDic; j++) {
			for (int k=0; k<diccionario[j].size(); k++) {
				if (dic[j][k] == ' ')
					dic[j][k] = 'A';
				else if (dic[j][k] == 'Z')
					dic[j][k] = ' ';
				else
					dic[j][k] +=1;
			}
		}

	}

	cout << "DELAY " << delay << endl;

	string result = "";
	char cc;
	for (int l=0; l<phrase.size(); l++) {
		char c = phrase.at(l);
		if (c == ' ') {
			cc = 63 + delay;
		}
		else if (c+delay==91) {
			cc = ' ';
		}
		else if (c+delay>91) {
			cc = c+delay-31;
		}
		else {
			cc = c + delay-2;
		}
		result += cc;


	}
	cout << result << endl;

	return 0;
}

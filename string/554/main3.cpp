#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string diccionario[100];
	string s;
	int i=0;
	while(getline(cin, s)) {
		if (s.compare("#") == 0)
			break;
		diccionario[i] = s;
		i++;
	}

	int tamDic = i-1;

	string phrase;
	getline(cin, phrase);
	int tam = phrase.size();
	char letras[tam];
	phrase.copy(letras, tam);

	bool found = false;
	bool valido;

	int puntero = 0;

	int betterDelay;
	int betterWords = 0;
	string result;

	int delay;
	int words;

	for (int i=0; i<27; i++) {

		words = 0;

		for (int j=0; j<tam; j++) {

			for (int k=0; k<tamDic; k++) {
				string palabra = diccionario[k];
				valido = true;
				for (int l=0; l<palabra.size(); l++) {
					if (letras[j+l] != palabra.at(l)) {
						valido = false;
						break;
					}
				}
				if (valido == true) {
					words++;
				}
			}


			if (letras[j] == ' ')
				letras[j] = 'A';
			else if (letras[j] == 'Z')
				letras[j] = ' ';
			else
				letras[j] = letras[j] + 1;
		}

		if (words > betterWords) {
			betterWords = words;
			betterDelay = i;
		}

		puntero++;
	}

	for (int i=0; i<tam; i++) {
		if (phrase.at(i) == ' ')
			cout << (char)('A' + delay-1);
		else if (phrase.at(i) == 'Z')
			cout << (char)(' ' + delay-1);
		else
			cout << (char)(phrase.at(i) + delay);
	}
	cout << endl;


	return 0;
}

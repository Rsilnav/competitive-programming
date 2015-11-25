#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);

	vector<string> diccionario;
	vector<string> ordered;
	vector<string> solucion;

	string entrada;
	while (cin >> entrada && entrada != "#") {
		diccionario.push_back(entrada);
		transform(entrada.begin(), entrada.end(), entrada.begin(), ::tolower);
		sort(entrada.begin(), entrada.end());
		ordered.push_back(entrada);
	}

	bool anan;

	for (int i=0; i<ordered.size(); i++) {
		anan = true;
		for (int j=0; j<ordered.size(); j++) {
			if (i == j) continue;
			if (ordered.at(i).size() != ordered.at(j).size()) {
				continue;
			}
			if (ordered.at(i) == ordered.at(j)) {
				anan = false;
				break;
			}
		}
		if (anan) {
			solucion.push_back(diccionario.at(i));
		}
	}

	sort(solucion.begin(), solucion.end());
	for (int i=0; i<solucion.size(); i++) {
		cout << solucion.at(i) << endl;
	}

	return 0;
}

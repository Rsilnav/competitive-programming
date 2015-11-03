#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;

	vector<int> mbDirecciones;
	vector<bool> mbMovido;
	vector<int> posiciones;
	vector<int> posicionesIniciales;

	int L, T, N;

	for (int cas=0; cas<cases; cas++) {

		// Entrada de datos
		cin >> L >> T >> N;
		for (int j=0; j<N; j++) {
			int pos;
			char c;
			cin >> pos >> c;
			posiciones.push_back(pos);
			if (c == 'R')
				mbDirecciones.push_back(1);
			else if (c == 'L')
				mbDirecciones.push_back(-1);
		}

		for (int i=0; i<N; i++) {
			posicionesIniciales.push_back(i);
		}

		for (int i=0; i<N; i++) {
			mbMovido.push_back(false);
		}

		int n, i, j, temp1, temp2, temp3;
		n = posiciones.size();
		for (int i=1; i<n-2; i++) {
			j = n-1;
			temp1 = posiciones[i];
			temp2 = mbDirecciones[i];
			temp3 = posicionesIniciales[i];
			while (j>=0 && posiciones[j] > temp1) {
				posiciones[j+1] = posiciones[j];
				mbDirecciones[j+1] = mbDirecciones[j];
				posicionesIniciales[j+1] = posicionesIniciales[j];
				j = j-1;
			}
			posiciones[j+1] = temp1;
			mbDirecciones[j+1] = temp2;
			posicionesIniciales[j+1] = temp3;

		}


		while (T--) {

			for (int i=0; i<N-1; i++) {
				if (!mbMovido[i] && abs(posiciones[i] - posiciones[i+1]) == 1 && mbDirecciones[i] == 1 && mbDirecciones[i+1] == -1) {
					mbDirecciones[i] *= -1;
					mbDirecciones[i+1] *= -1;
					mbMovido[i] = true;
					mbMovido[i+1] = true;
					i++;
				}
			}

			for (int i=0; i<N; i++) {
				if (!mbMovido[i] && posiciones[i] != -1) {
					if (posiciones[i] <= 0 && mbDirecciones[i] == -1) {
						posiciones[i] = -1;
						mbMovido[i] = true;
					}
					else if (posiciones[i] >= L && mbDirecciones[i] == 1) {
						posiciones[i] = -1;
						mbMovido[i] = true;
					}

					if (!mbMovido[i]) {
						posiciones[i] = posiciones[i] + mbDirecciones[i];
						mbMovido[i] = true;
					}

				}
			}

			for (int i=0; i<N; i++) {
				if (posiciones[i] != -1) {
					if (i-1 >= 0 && posiciones[i] == posiciones[i-1]) {
						mbDirecciones[i] *= -1;
					}
					else if (i+1 < N && posiciones[i] == posiciones[i+1]) {
						mbDirecciones[i] *= -1;
					}

				}
				mbMovido[i] = false;
			}
		}

		// Salida de datos
		cout << "Case #" << cas+1 << ":\n";
		for (int j=0; j<N; j++) {
			int pos = posicionesIniciales[j];
			if (posiciones[pos] == -1) {
				cout << "Fell off" << endl;
			}
			else {
				cout << posiciones[pos] << " ";
				if (posiciones[pos] == posiciones[pos-1] || posiciones[pos] == posiciones[pos+1]) {
					cout << "Turning";
				}
				else {
					if (mbDirecciones[pos] == 1) {
						cout << "R";
					}
					else {
						cout << "L";
					}
				}
				cout << endl;
			}
		}

		// Limpieza de vectores
		mbDirecciones.clear();
		mbMovido.clear();
		posiciones.clear();
		posicionesIniciales.clear();
		cout << endl;
	}
	return 0;
}

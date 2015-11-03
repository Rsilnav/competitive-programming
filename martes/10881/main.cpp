#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;

	vector<int> inicial;
	vector<int> movimiento;
	vector<int> sumado;
	vector<int> ordenado;
	vector<int> indiceOrdenado;
	vector<int> resultado;


	int L, T, N;

	for (int cas=0; cas<cases; cas++) {

		// Entrada de datos
		cin >> L >> T >> N;

		int temp;
		char c;
		for (int i=0; i<N; i++) {
			cin >> temp >> c;
			if (c=='R')
				movimiento.push_back(1);
			if (c=='L')
				movimiento.push_back(-1);
			inicial.push_back(temp);
		}

		for (int i=0; i<N; i++) {
			sumado.push_back(inicial.at(i) + T*movimiento.at(i));
		}

		for (int i=0; i<N; i++) {
			indiceOrdenado.push_back(i);
		}

		int n, i, j, temp1, temp2;
		n = inicial.size();
		for (int i=1; i<n-2; i++) {
			j = n-1;
			temp1 = inicial[i];
			temp2 = indiceOrdenado[i];
			while (j>=0 && inicial[j] > temp1) {
				inicial[j+1] = inicial[j];
				indiceOrdenado[j+1] = indiceOrdenado[j];
				j = j-1;
			}
			inicial[j+1] = temp1;
			indiceOrdenado[j+1] = temp2;
		}



		n = inicial.size();
		for (int i=1; i<n-2; i++) {
			j = n-1;
			temp1 = sumado[i];
			temp2 = movimiento[i];
			while (j>=0 && sumado[j] < temp1) {
				sumado[j+1] = sumado[j];
				movimiento[j+1] = movimiento[j];
				j = j-1;
			}
			sumado[j+1] = temp1;
			movimiento[j+1] = temp2;
		}



		cout << "Case #" << cas+1 << ":" << endl;

		for (int a=0; a<N; a++) {

			cout << sumado.at(a) << " ";
			if (movimiento.at(a) == 1)
			 	cout << "R" << endl;
			else if (movimiento.at(a) == -1)
			 	cout << "L" << endl;

		}


		// Limpieza de vectores
		inicial.clear();
		movimiento.clear();
		sumado.clear();
		ordenado.clear();
		indiceOrdenado.clear();
		resultado.clear();

		cout << endl;
	}
	return 0;
}

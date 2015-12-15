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
	vector<int> indiceOrdenado;
	vector<int> initialState;


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


		int n, temp1, temp2;
		int k, j;

		initialState = inicial;

		n = inicial.size();
		for (int i = 0; i < n; i++){
			k = i;
			while (k > 0 && inicial[k] < inicial[k-1]){
			  temp1 = inicial[k];
			  inicial[k] = inicial[k-1];
			  inicial[k-1] = temp1;
			  k--;
		  }
		}

		for (int a=0; a<N; a++) {
			for (int b=0; b<N; b++) {
				if (initialState.at(a) == inicial.at(b)) {
					indiceOrdenado.push_back(b);
					break;
				}
			}
		}

		n = sumado.size();
		for (int i = 0; i < n; i++){
			k = i;
			while (k > 0 && sumado[k] < sumado[k-1]){
			  temp1 = sumado[k];
			  sumado[k] = sumado[k-1];
			  sumado[k-1] = temp1;
				temp2 = movimiento[k];
			  movimiento[k] = movimiento[k-1];
			  movimiento[k-1] = temp2;
			  k--;
		  }
		}

		cout << "Case #" << cas+1 << ":" << endl;

		for (int a=0; a<N; a++) {
			int pos = indiceOrdenado.at(a);

			if (sumado.at(pos) < 0 || sumado.at(pos) > L) {
				cout << "Fell off" << endl;
				continue;
			}

			cout << sumado.at(pos) << " ";
			if (pos-1 >= 0 && sumado.at(pos) == sumado.at(pos-1)) {
				cout << "Turning" << endl;
			}
			else if (pos+1 < N && sumado.at(pos) == sumado.at(pos+1)) {
				cout << "Turning" << endl;
			}
			else {
				if (movimiento.at(pos) == 1)
				 	cout << "R" << endl;
				else if (movimiento.at(pos) == -1)
				 	cout << "L" << endl;
			}
		}

		inicial.clear();
		movimiento.clear();
		sumado.clear();
		indiceOrdenado.clear();
		cout << endl;

	}
	return 0;
}

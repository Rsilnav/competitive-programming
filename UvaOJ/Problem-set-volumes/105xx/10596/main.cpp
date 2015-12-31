#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int nodes, roads;
	int x, y;
	bool isEuler;

	while (cin >> nodes >> roads) {
		int m[nodes][nodes];
		for (int i=0; i<nodes; i++)
			for (int j=0; j<nodes; j++)
				m[i][j] = 0;

		for (int i=0; i<roads; i++) {
			cin >> x >> y;
			m[x][y] += 1;
			m[y][x] += 1;
		}

		isEuler = true;
		int grados[nodes];
		for (int i=0; i<nodes; i++)
			grados[i] = 0;

		int c;
		for (int i=0; i<nodes; i++) {
			c = 0;
			for (int j=0; j<nodes; j++) {
				//cout << i << " " << j << " " << m[i][j] << endl;
				if (m[i][j] > 0) {
					c+=m[i][j];
				}
			}
			grados[i] = c;
		}

		int numNodos = 0;
		for (int i=0; i<nodes; i++) {
			if (grados[i] > 0) numNodos++;
			if (grados[i]%2 != 0) {
				isEuler = false;
				break;
			}
		}

		bool visitado[nodes];
		for (int i=0; i<nodes; i++)
			visitado[i] = false;


		deque<int> pila;

		for (int i=0; i<nodes; i++) {
			if (grados[i] > 0) {
				pila.push_front(i);
				visitado[i] = true;

				while (!pila.empty()) {
					int nodoAct = pila.front();
					visitado[nodoAct] = true;
					pila.pop_front();

					for (int j=0; j<nodes; j++) {
						if (m[nodoAct][j] > 0) {
							if (!visitado[j] && find(pila.begin(), pila.end(), j) == pila.end()) {
								pila.push_front(j);
							}
							visitado[j] = true;
						}
					}
				}

				break;
			}
		}

		for (int i=0; i<nodes; i++) {
			if (grados[i] > 0 && !visitado[i]) {
				isEuler = false;
				break;
			}
		}

		if (roads == 0) {
			isEuler = false;
		}

		if (isEuler) {
			cout << "Possible" << endl;
		}
		else {
			cout << "Not Possible" << endl;
		}


	}
	return 0;
}

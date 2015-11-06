#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<vector<double>> findPaths(vector<vector<double>> data, vector<vector<double>> opt, double minimo, vector<double> filas) {
	vector<vector<double>> caminos;
	if (minimo < 0)
    return caminos;

  double col = filas.size();
  double count = 0;

  if (col == opt[0].size()) {
		vector<double> cam;
    for (double i=0; i<filas.size(); i++) {
      //cout << filas[i]+1;
			cam.push_back(filas[i]+1);
      //if (i < filas.size() - 1)
        //cout << " ";
    }
		caminos.push_back(cam);
    //cout << endl;
    return caminos;
  }
  else {
    for (double i=-1; i<=1; i++) {
      double temp = filas.back() + i;
      if (temp < 0)
        temp = data.size() -1;
      if (temp > data.size()-1)
        temp = 0;

      if (opt[temp][col] == minimo) {
        filas.push_back(temp);
				vector<vector<double>> temp2;
        //count += findPaths(data, opt, minimo-data[temp][col], filas);
				temp2 = findPaths(data, opt, minimo-data[temp][col], filas);
				caminos.insert(caminos.end(), temp2.begin(), temp2.end());
        filas.pop_back();
      }
    }
  }

  return caminos;
}

void pureDynamicProgramming(vector<vector<double>> data, int rows, int cols) {
  // Inicializamos la matriz que tendra los valores optimos
  // de coste de dicha celda hasta la ultima columna
  vector<vector<double>> optimos;
  for (double i=0; i<rows; i++) {
    vector<double> temp;
    for (double j=0; j<cols; j++) {
      temp.push_back(0);
    }
    optimos.push_back(temp);
  }

  // Rellenamos la ultima columna con los propios numeros
  for (double i=0; i<rows; i++) {
    optimos[i][cols-1] = data[i][cols-1];
  }

  // Para el resto de las columnas, su valor sera el optimo
  // de las tres posibles mas su coste
  double a, b, c;
  for (double j=cols-2; j>=0; j--) {
    for (double i=0; i<rows; i++) {
      if (i-1 < 0)
        a = optimos[rows-1][j+1];
      else
        a = optimos[i-1][j+1];
      if (i+1 > rows-1)
        b = optimos[0][j+1];
      else
        b = optimos[i+1][j+1];
      c = optimos[i][j+1];
      optimos[i][j] = min(a, min(b, c)) + data[i][j];
    }
  }

  // Buscamos cual ha sido el minimo en la primera columna
  double minimo = numeric_limits<double>::max();
  for (double i=0; i<rows; i++) {
    if (optimos[i][0] < minimo)
      minimo = optimos[i][0];
  }

  // Imprimimos el resultado
  vector<double> filas;
  double paths = 0;
	vector<vector<double>> caminos;
	vector<vector<double>> temp;
  for (double i=0; i<rows; i++) {
    if (optimos[i][0] == minimo) {
      filas.push_back(i);
      temp = findPaths(data, optimos, minimo-data[i][0], filas);
			caminos.insert(caminos.end(), temp.begin(), temp.end());
      filas.pop_back();
    }
  }

	cout << caminos << endl;
	
	//sort(caminos.begin(), caminos.end());
	//for (int i=0; i<caminos[0].size(); i++) {
		//if (i>0)
			//cout << " ";
		//cout << caminos[0][i];
	//}
	//cout << endl;


	/*
	for (int i=0; i<caminos.size(); i++) {
		for (int j=0; j<caminos[0].size(); j++) {
			if (j>0)
				cout << " ";
				cout << caminos[i][j];
		}
		cout << endl;
	}*/


  cout << minimo << endl;
}

int main() {
	ios_base::sync_with_stdio (false);
	double rows, cols;
	while (cin >> rows >> cols) {

    // Guardamos los datos a procesar en la matriz 'data'
    vector<vector<double>> data;
	  for (double i=0; i<rows; i++) {
      vector<double> temp;
	    for (double j=0; j<cols; j++) {
        double x;
        cin >> x;
        temp.push_back(x);
	    }
      data.push_back(temp);
	  }

		pureDynamicProgramming(data, rows, cols);
	}

	return 0;
}

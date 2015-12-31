#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct jugador {
    string name;
    int att;
    int def;
};

bool ordenar_mejores(const jugador &a, const jugador &b) {
    return a.att > b.att || (a.att == b.att && a.def < b.def) || (a.att == b.att && a.def == b.def && a.name < b.name);
}

bool ordenar_nombre(const jugador &a, const jugador &b) {
    return a.name < b.name;
}

int main(void) {
  int cases;
  jugador equipo[10];

  cin >> cases;

  for (int i=0; i<cases; i++) {
    for (int j=0; j<10; j++) {
      cin >> equipo[j].name >> equipo[j].att >> equipo[j].def;
    }

    sort (equipo, equipo + 10, ordenar_mejores);
    sort (equipo, equipo + 5, ordenar_nombre);
    sort (equipo + 5, equipo + 10, ordenar_nombre);

    cout << "Case " << i+1 << ":" << endl;
    cout << "(";
    for (int j=0; j<5; j++) {
        if (j > 0) cout << ", ";
        cout << equipo[j].name;
    }
    cout << ")" << endl;
    cout << "(";
    for (int j=5; j<10; j++) {
        if (j > 5) cout << ", ";
        cout << equipo[j].name;
    }
    cout << ")" << endl;
  }

    return 0;
}

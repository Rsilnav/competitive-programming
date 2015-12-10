#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    unordered_set<int> angles;
    int hora, minuto;
    hora=0, minuto=0;
    int a, b;
    int diff;

    while(hora<60) {
      if (hora > minuto) {
        a = hora;
        b = minuto;
      }
      else {
        a = minuto;
        b = hora;
      }
      diff = min(60+b-a, a-b);
      angles.insert(diff*6);
      minuto++;
      minuto = minuto%60;
      if (minuto%12==0) {
        hora++;
      }
    }

    int entrada;
    while (cin >> entrada) {
      if (angles.count(entrada) > 0) {
        cout << "Y" << endl;
      }
      else {
        cout << "N" << endl;
      }
    }
    return 0;
}

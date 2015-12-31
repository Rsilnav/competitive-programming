#include <iostream>

using namespace std;

string dias_semana[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
int comienza_en[] = {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};

int main() {
    ios_base::sync_with_stdio (false);
    int cases;
    int m, d;
    cin >> cases;
    for (int i=0; i<cases; i++) {
      cin >> m >> d;
      m--;
      d = (d - 1) + comienza_en[m];
      d %= 7;
      cout << dias_semana[d] << endl;
    }
    return 0;
}

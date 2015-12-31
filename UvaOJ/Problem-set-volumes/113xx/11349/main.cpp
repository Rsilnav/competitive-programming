#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
  cin >> cases;
  char s;
  long long tam, n;
  bool sim;
  for (int i=0; i<cases; i++) {
    cin >> s;
    cin >> s;
    cin >> tam;
    long long m[tam][tam];
    for (int x=0; x<tam; x++) {
      for (int y=0; y<tam; y++) {
        cin >> n;
        m[x][y] = n;
      }
    }

    sim = true;
    //cx = tam/2;
    //cy = tam/2;

    for (int x=0; x<tam; x++) {
      for (int y=0; y<tam; y++) {
        if (m[x][y] < 0) {
          sim = false;
        }
        if (m[x][y] != m[tam-1-x][tam-1-y]) {
          //cout << m[x][y] << " " << m[tam-1-x][tam-1-y] << endl;
          sim = false;
        }
      }
    }

    if (sim) {
      cout << "Test #" << i+1 << ": Symmetric." << endl;
    }
    else {
      cout << "Test #" << i+1 << ": Non-symmetric." << endl;
    }
  }
	return 0;
}

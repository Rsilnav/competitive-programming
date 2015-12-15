#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio (false);

  int cases;
  cin >> cases;

  int len;
  string field;
  int count;
  for (int i=0; i<cases; i++) {
    cin >> len;
    cin.ignore();
    getline(cin, field);

    count = 0;
    for (int j=0; j<field.size(); j++) {
      if (field[j] == '.') {
        count++;
        field[j] = '#';
        if (j < field.size()-1) field[j+1] = '#';
        if (j < field.size()-2) field[j+2] = '#';
      }
    }

    cout << "Case " << i+1 << ": " << count << endl;
  }

  return 0;
}

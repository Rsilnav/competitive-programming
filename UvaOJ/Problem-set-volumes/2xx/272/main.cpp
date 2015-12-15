#include <iostream>
#include <math.h>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    string line;
    bool inQuotes = false;
    char letter;

    while (getline(cin, line)) {
        REP(i, 0, line.length()) {
            letter = line[i];
            if (letter == '\"') {
                if (inQuotes)
                    cout << "\'\'";
                else
                    cout << "``";
                inQuotes = !inQuotes;
            } else {
                cout << letter;
            }
        }
        cout << endl;
    }
}

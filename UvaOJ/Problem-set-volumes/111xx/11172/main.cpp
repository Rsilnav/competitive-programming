#include <iostream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    ios_base::sync_with_stdio (false);
    int cases;
    cin >> cases;
    cin.ignore();

    int a, b;

    REP(i, 0, cases) {
        cin >> a >> b;
        if (a>b)
            cout << ">" << endl;
        else if (a<b)
            cout << "<" << endl;
        else
            cout << "=" << endl;
    }
}

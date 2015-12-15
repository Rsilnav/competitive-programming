#include <iostream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    ios_base::sync_with_stdio (false);
    int cases;
    cin >> cases;
    int x, y, z;
    REP(i, 1, cases+1) {
        cout << "Case " << i << ": ";
        cin >> x >> y >> z;
        if (x>20 || y>20 || z>20)
            cout << "bad" << endl;
        else
            cout << "good" << endl;
    }
}

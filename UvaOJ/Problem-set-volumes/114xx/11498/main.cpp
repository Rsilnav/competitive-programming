#include <iostream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    ios_base::sync_with_stdio (false);

    int cases;
    int midx, midy;
    int x, y;
    while(true) {
        cin >> cases;
        if (cases == 0)
            break;

        cin >> midx >> midy;

        REP(i, 0, cases) {
            cin >> x >> y;
            if (x==midx || y==midy)
                cout << "divisa" << endl;
            else if (x>midx && y>midy)
                cout << "NE" << endl;
            else if (x>midx && y<midy)
                cout << "SE" << endl;
            else if (x<midx && y>midy)
                cout << "NO" << endl;
            else if (x<midx && y<midy)
                cout << "SO" << endl;
        }
    }
}

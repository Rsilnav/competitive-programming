#include <iostream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    ios_base::sync_with_stdio (false);
    int cases;
    cin >> cases;
    cin.ignore();

    REP(i, 0, cases) {
        int a, b, c;
        int mid;
        cin >> a >> b >> c;

        if (c>a && a>b || b>a && a>c)
            mid = a;
        else if (a>b && b>c || c>b && b>a)
            mid = b;
        else if (b>c && c>a || a>c && c>b)
            mid = c;

        cout << "Case " << i+1 << ": " << mid << endl;
    }
}

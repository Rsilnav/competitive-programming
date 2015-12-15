#include <iostream>
#include <math.h>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;
int cycle(int x) {
    if (x == 1)
        return 1;
    int t;
    if (x % 2 == 0)
        t = x >> 1;
    else
        t = 3*x+1;
    return 1 + cycle(t);
}

int main() {
    int a, b, c, temp;

    while (cin >> a >> b) {
        c = 0;
        cout << a << " " << b;
        if (b < a) {
            temp = a;
            a = b;
            b = temp;
        }
        REP(i, a, b+1) {
            temp = cycle(i);
            if (temp > c)
                c = temp;
        }
        cout << " " << c << endl;
    }
}

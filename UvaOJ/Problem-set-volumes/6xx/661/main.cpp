#include <iostream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    int a, b, c;
    int sequence = 1;

    while (cin >> a >> b >> c) {
        if (a==0 && b==0 && c==0)
            break;    
        cout << "Sequence " << sequence << endl;
    
        int flags[a];
        int consume[a];

        REP(i, 0, a) {
            flags[i] = 0;
            cin >> consume[i];
        }

        int maxpower = 0;
        int power = 0;
        int s;

        REP(i, 0, b) {
            cin >> s;
            s = s-1;
            if (flags[s] == 0) {
                flags[s] = 1;
                power += consume[s];
            } else {
                flags[s] = 0;
                power -= consume[s];
            }
            if (power > maxpower)
                maxpower = power;
        }

        if (maxpower > c)
            cout << "Fuse was blown." << endl;
        else
            cout << "Fuse was not blown." << endl << "Maximal power consumption was " << maxpower << " amperes." << endl;

        cout << endl;
        sequence++;
    }
}

#include <iostream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

float angle(int num1, int num2) {
    if (num2>num1)
        return 9*(40+num1-num2);
    return 9*(num1-num2);
}

int main() {
    ios_base::sync_with_stdio (false);
    int a, b, c, d, x;

    while(true) {
        cin >> a >> b >> c >> d;
        if (a==0 && b==0 && c==0 && d==0)
            break;

        x = 1080 + angle(a, b) + angle(c, b) + angle(c, d);
        cout << x << endl;
    }
}

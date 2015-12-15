#include <iostream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    int h, u, d, f;
    while (cin >> h >> u >> d >> f) {
        if (h==0) {
            break;
        }
        int day = 0;
        float real_h = 0;
        float ups = (float) u;

        while(true) {
            day = day + 1;
            ups = (float)u - (float)u * ((float)f*(day-1)/100);
            if (ups < 0)
                ups = 0;
            
            real_h = real_h + ups;
            //cout << "El caracol sube " << ups << endl;
            if (real_h > h) {
                cout << "success on day " << day << endl;
                break;
            }
            real_h = real_h - d;
            if (real_h < 0) {
                cout << "failure on day " << day << endl;
                break;
            }
        }
    }
}

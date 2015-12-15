#include <iostream>
#include <stdlib.h>
#include <iomanip>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int secsdiff(int h0, int m0, int s0, int h1, int m1, int s1) {
    int hour0 = h0*3600+m0*60+s0;
    int hour1 = h1*3600+m1*60+s1;
    if (hour1<hour0)
        hour1 = hour1 + 24*3600;
    return hour1-hour0;
}

int main() {
    ios_base::sync_with_stdio (false);
    string line;
    float distance = 0;
    double speed = 0;
    int h, m, s;
    int h0=0,m0=0,s0=0;

    while(getline(cin, line)) {

        h = (line[0] - '0') * 10 + (line[1] - '0');
        m = (line[3] - '0') * 10 + (line[4] - '0');
        s = (line[6] - '0') * 10 + (line[7] - '0');

        distance = distance + secsdiff(h0,m0,s0,h,m,s) * (double)speed/3600;
        
        if (line.size() > 8) {
            speed = 0;
            int tamspeed = line.size() - 8;
            speed = atoi(line.substr(8, tamspeed).c_str());
        }
        else if (line.size() == 8) {
            cout << setfill('0') << setw(2) << h;
            cout << ":" << setfill('0') << setw(2) << m;
            cout << ":" << setfill('0') << setw(2) << s << " ";
            cout << fixed << setprecision(2) << distance << " km" << endl;
        }

        h0 = h;
        m0 = m;
        s0 = s;
    }
}

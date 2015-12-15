#include <iostream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    char line1[13] = {'`','1','2','3','4','5','6','7','8','9','0','-','='};
    char line2[13] = {'Q','W','E','R','T','Y','U','I','O','P','[',']','\\'};
    char line3[11] = {'A','S','D','F','G','H','J','K','L',';','\''};
    char line4[10] = {'Z','X','C','V','B','N','M',',','.','/'};

    char ch;
    while (cin.get(ch)) {
        if (ch == ' ' || ch == '\n') {
            cout << ch;
        } else {
            REP(i, 0, 13)
                if (line1[i] == ch)
                    cout << line1[i-1];
            REP(i, 0, 13)
                if (line2[i] == ch)
                    cout << line2[i-1];
            REP(i, 0, 11)
                if (line3[i] == ch)
                    cout << line3[i-1];
            REP(i, 0, 10)
                if (line4[i] == ch)
                    cout << line4[i-1];

        }
    }
}

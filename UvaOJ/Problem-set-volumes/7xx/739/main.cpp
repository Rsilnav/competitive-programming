#include <iostream>
#include <string.h>
#include <iomanip>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

char numOf(char n) {
    if (n=='B' || n=='P' || n=='V' || n=='F')
        return '1';
    if (n=='C' || n=='S' || n=='K' || n=='G' || n=='J' || n=='Q' || n=='X' || n=='Z')
        return '2';
    if (n=='D' || n=='T')
        return '3';
    if (n=='L')
        return '4';
    if (n=='M' || n=='N')
        return '5';
    if (n=='R')
        return '6';
    return '0';
}

string toSoundex(string name) {
    string result = "";
    result = result + name[0];

    char last = numOf(name[0]);
    char now;

    REP(i, 1, name.size()) {
        now = name[i];
        if (result.size() <= 3) {
            if (numOf(now) != last && numOf(now) != '0')
                result = result + numOf(now);
            last = numOf(now);
        }
    }

    REP(i, result.size(), 4)
        result += '0';

    return result;
}

int main() {
    string name;

    cout << setw(9) << "" << setw(25) << left << "NAME" << "SOUNDEX CODE" << endl;

    while(getline(cin, name)) {
        if(name=="")
            break;
        cout << setw(9) << "" << setw(25) << left << name << toSoundex(name) << endl;
    }
    cout << setw(19) << "" << "END OF OUTPUT" << endl;
}

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    ios_base::sync_with_stdio (false);
    int cases;
    string inputStr, tempStr;
    int maxnum, num;
    cin >> cases;
    cin.ignore();
    REP(i, 1, cases+1) {
        maxnum = 0;
        getline(cin, inputStr);
        istringstream token(inputStr);
        while(token) {
            token >> tempStr;
            num = atoi(tempStr.c_str());
            if (num>maxnum) maxnum = num;
        }
        cout << "Case " << i << ": " << maxnum << endl;
    }
}

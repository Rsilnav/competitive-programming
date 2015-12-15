#include <iostream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    ios_base::sync_with_stdio (false);
    int events;
    int balance;
    int reason;
    int numcase = 0;

    while(true) {
        cin >> events;
        if (events==0)
            break;
        numcase++;
        balance = 0;

        while(events--) {
            cin >> reason;
            if (reason==0)
                balance--;
            else
                balance++;
        }
        cout << "Case " << numcase << ": " << balance << endl;
    }
}

#include <iostream>

#define REP(i, a, b) \
    for (int i = a; i < b; i++)

using namespace std;

int main() {
    ios_base::sync_with_stdio (false);
    int people, budget, hotels, weeks;
    int totalcost;
    int cost, freebeds;

    while(cin >> people >> budget >> hotels >> weeks) {
        totalcost = budget + 1;
        REP(i, 0, hotels) {
            cin >> cost;

            REP(j, 0, weeks) {
                cin >> freebeds;
                if (freebeds>=people)
                    if (cost*people<totalcost)
                        totalcost = cost*people;
            }
        }

        if (totalcost<=budget)
            cout << totalcost << endl;
        else 
            cout << "stay home" << endl;
    }
}

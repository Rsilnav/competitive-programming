#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  ios_base::sync_with_stdio (false);

  int N,m,k;
  vector<int> people;
  int pointer1;
  int pointer2;

  while (cin >> N >> k >> m && N && k && m) {
    pointer1 = N-1;
    pointer2 = 0;
    for (int i=1; i<=N; i++) people.push_back(i);

    while (people.size() > 0) {

      for (int i=0; i<k; i++) {
        pointer1++;
        if (pointer1 >= people.size()) {
          pointer1 = 0;
        }
      }
      for (int i=0; i<m; i++) {
        pointer2--;
        if (pointer2 < 0) {
          pointer2 = people.size()-1;
        }
      }

      if (pointer1 == pointer2) {
        cout << setfill(' ') << setw(3) << people.at(pointer1);
        people.erase(people.begin() + pointer1);
        pointer1--;
      }
      else if (pointer1 < pointer2) {
        cout << setfill(' ') << setw(3) << people.at(pointer1);
        cout << setfill(' ') << setw(3) << people.at(pointer2);
        people.erase(people.begin() + pointer2);
        people.erase(people.begin() + pointer1);
        pointer1--;
        pointer2--;
      }
      else if (pointer1 > pointer2) {
        cout << setfill(' ') << setw(3) << people.at(pointer1);
        cout << setfill(' ') << setw(3) << people.at(pointer2);
        people.erase(people.begin() + pointer1);
        people.erase(people.begin() + pointer2);
        pointer1-=2;
      }

      if (people.size() > 0) {
        cout << ",";
      }
    }

    cout << endl;

  }

  return 0;
}

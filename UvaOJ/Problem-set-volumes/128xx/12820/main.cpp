#include <iostream>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int num_w, count, cases, n;
  map<char, int> appears;
  list<int> mylist;
  string word;
  bool flag;
  cases = 1;
  while (cin >> num_w) {
    count = 0;
    for (int i=0; i<num_w; i++) {
      cin >> word;
      for (int i=0; i<word.size(); i++) {
        appears[word[i]]++;
      }
      if (appears.size() < 2) {
        continue;
      }
      for (map<char, int>::iterator it=appears.begin(); it!=appears.end(); ++it) {
        mylist.push_back(it->second);
      }
      n = mylist.size();
      mylist.sort();
      mylist.unique();
      if (n == mylist.size()) count++;
      appears.clear();
      mylist.clear();
    }
    cout << "Case " << cases << ": " << count << endl;
    cases++;
  }
  return 0;
}

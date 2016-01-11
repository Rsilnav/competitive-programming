#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<char, int>  &p1, const pair<char, int> &p2)
{
  return (p1.second > p2.second) || (p1.second == p2.second && p1.first < p2.first);
}

int main() {
	ios_base::sync_with_stdio (false);
	int l;
  cin >> l;
  cin.ignore();
  string line;

  map<char, int> freq;

  for (int i=0; i<l; i++) {
    getline(cin, line);
    for (int j=0; j<line.size(); j++) {
      char c = line.at(j);
      if (c<='Z' && c>='A') {
        freq[c]++;
      }
      else if (c<='z' && c>='a') {
        freq[c-'a'+'A']++;
      }
    }
  }

  vector<pair<char, int>> v(freq.begin(), freq.end());
  sort(v.begin(), v.end(), cmp);
  for (int x=0; x<v.size(); x++) {
    cout << v.at(x).first << " " << v.at(x).second << endl;
  }

	return 0;
}

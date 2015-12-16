#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> months_haab = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
vector<string> days_tzolkin = {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
  cin >> cases;
  cout << cases << endl;

  string day;
  string month;

  int amount;
	int s_day, s_month, s_year;
  int r_day, r_month, r_year;

  for (int i=0; i<cases; i++) {
    cin >> day >> month >> s_year;

    day = day.substr(0, day.size()-1);
		s_day = stoi(day);
    vector<string>::iterator result = find(months_haab.begin(), months_haab.end(), month);
    s_month = result - months_haab.begin();
    amount = s_year * 365 + s_month*20 + s_day;

    r_year = amount/260;
    amount = amount%260;
    r_month = amount%20;
    r_day = amount%13+1;

    cout << r_day << " " << days_tzolkin[r_month] << " " << r_year << endl;
  }
	return 0;
}

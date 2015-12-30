#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	string num, s, t;

  bool div4, div11, div5, div3, div100, div400;
  long sum3, sum11;
  bool leap, hulu, bulu;
  bool first = true;

  while (cin >> num) {

    if (first) {
      first = false;
    }
    else {
      cout << endl;
    }

    s = num.substr(num.size()-2, 2);
    if (stoi(s) % 4 == 0) {
      div4 = true;
    }
    else {
      div4 = false;
    }

    if (s == "00") {
      div100 = true;
      t = num.substr(num.size()-4, 2);
      if (stoi(t) % 4 == 0) {
        div400 = true;
      }
      else {
        div400 = false;
      }
    }
    else {
      div100 = false;
      div400 = false;
    }

    if (s.substr(1, 1) == "0" || s.substr(1, 1) == "5") {
      div5 = true;
    }
    else {
      div5 = false;
    }

    sum3 = 0;
    sum11 = 0;
    for (int i=0; i<num.size(); i++) {
      sum3 += num.at(i)-48;
      if (i%2==0) {
        sum11 += (num.at(i)-48);
      }
      else {
        sum11 -= (num.at(i)-48);
      }
    }

    if (sum3%3==0) {
      div3 = true;
    }
    else {
      div3 = false;
    }

    if (sum11 < 0) {
      sum11 *= -1;
    }

    if (sum11%11==0) {
      div11 = true;
    }
    else {
      div11 = false;
    }

    leap = false;
    hulu = false;
    bulu = false;
    if (div4 && !div100 || div400) {
      leap = true;
    }
    if (div3 && div5) {
      hulu = true;
    }
    if (leap && div5 && div11) {
      bulu = true;
    }

    if (leap) {
      cout << "This is leap year." << endl;
    }
    if (hulu) {
      cout << "This is huluculu festival year." << endl;
    }
    if (bulu) {
      cout << "This is bulukulu festival year." << endl;
    }
    if (!leap && !hulu && !bulu) {
      cout << "This is an ordinary year." << endl;
    }
  }

	return 0;
}

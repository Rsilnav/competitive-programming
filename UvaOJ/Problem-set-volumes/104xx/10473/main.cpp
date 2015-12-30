#include <iostream>
#include <algorithm>

using namespace std;

void HexToDec(string hex) {
  long res = 0;
  reverse(hex.begin(), hex.end());
  long mul = 1;
  int num;
  char c;
  for (int i=0; i<hex.size(); i++) {
    c = hex.at(i);
    if (c >= 65 && c <= 90) {
      num = (int)(c-65+10);
    }
    else {
      num = (int)(c-48);
    }
    res += num*mul;
    mul *= 16;
  }
  cout << res << endl;
}

void DecToHex(long dec) {
  string res = "";
  if (dec == 0) {
    res = "0";
  }
  else {
    while (dec > 0) {
      int resto = dec%16;
      dec = dec / 16;
      if (resto < 10) {
        res = (char)(resto+48) + res;
      }
      else {
        resto -= 10;
        res = (char)(resto+65) + res;
      }
    }
  }
  cout << "0x" << res << endl;
}

int main() {
	ios_base::sync_with_stdio (false);
	string s;
  while (cin >> s && s.at(0) != '-') {
    if (s.substr(0, 2) == "0x") {
      HexToDec(s.substr(2, s.size()));
    }
    else {
      DecToHex(stoi(s));
    }
  }

	return 0;
}

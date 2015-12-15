#include <iostream>
#include <list>
#include <vector>

using namespace std;

int paloToInt(string s) {
  if (s.at(0) == 'K') {
    return 12;
  }
  else if (s.at(0) == 'Q') {
    return 11;
  }
  else if (s.at(0) == 'J') {
    return 10;
  }
  else if (s.at(0) == 'T') {
    return 9;
  }
  else if (s.at(0) == 'A') {
    return 0;
  }
  else {
    return s.at(0)-49;
  }
}

int main() {
	ios_base::sync_with_stdio (false);
	string in;
  vector<list<string>> mesa;
  list<string> pila;
  int cards;
  string card;
  int pos;
  while (cin >> in && in != "#") {
    for (int i=0; i<13; i++) {
      mesa.push_back(pila);
    }
    cards = 1;
    pos = paloToInt(in);
    mesa[12].push_back(in);

    for (int i=1; i<13; i++) {
      cin >> in;
      mesa[12-i].push_back(in);
    }
    for (int i=0; i<3; i++) {
      for (int j=0; j<13; j++) {
        cin >> in;
        mesa[12-j].push_back(in);
      }
    }

    card = mesa[12].front();
    mesa[12].pop_front();

    while (true) {
      pos = paloToInt(card);
      if (mesa[pos].empty()) {
        printf("%02d,%s\n", cards, card.c_str());
        break;
      }
      cards++;
      card = mesa[pos].front();
      mesa[pos].pop_front();
    }
    mesa.clear();
  }
	return 0;
}

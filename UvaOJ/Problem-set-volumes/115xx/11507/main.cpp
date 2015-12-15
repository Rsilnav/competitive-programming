#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int frags;
  string move;
  string dir;
  while (cin >> frags && frags) {
    dir = "+x";
    for (int i=1; i<frags; i++) {
      cin >> move;
      if (move == "No") continue;

      if (move == "+y") {
        if (dir == "+x") dir = "+y";
        else if (dir == "-x") dir = "-y";
        else if (dir == "+y") dir = "-x";
        else if (dir == "-y") dir = "+x";
      }
      else if (move == "-y") {
        if (dir == "+x") dir = "-y";
        else if (dir == "-x") dir = "+y";
        else if (dir == "+y") dir = "+x";
        else if (dir == "-y") dir = "-x";
      }
      else if (move == "+z") {
        if (dir == "+x") dir = "+z";
        else if (dir == "-x") dir = "-z";
        else if (dir == "+z") dir = "-x";
        else if (dir == "-z") dir = "+x";
      }
      else if (move == "-z") {
        if (dir == "+x") dir = "-z";
        else if (dir == "-x") dir = "+z";
        else if (dir == "+z") dir = "+x";
        else if (dir == "-z") dir = "-x";
      }

    }
    cout << dir << endl;
  }

	return 0;
}

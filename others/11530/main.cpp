#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	cin.ignore();
	string s;
	int press;
	for (int i=0; i<cases; i++) {
		press = 0;
		getline(cin, s);
		for (int j=0; j<s.size(); j++) {
			char c = s.at(j);
			if (c=='a' || c=='d' || c=='g' || c=='j' ||
					c=='m' || c=='p' || c=='t' || c=='w' || c==' ')
					press += 1;
			if (c=='b' || c=='e' || c=='h' || c=='k' ||
					c=='n' || c=='q' || c=='u' || c=='x')
					press += 2;
			if (c=='c' || c=='f' || c=='i' || c=='l' ||
					c=='o' || c=='r' || c=='v' || c=='y')
					press += 3;
			if (c=='s' || c=='z')
					press += 4;
		}
		cout << "Case #" << i+1 << ": " << press << endl;
	}
	return 0;
}

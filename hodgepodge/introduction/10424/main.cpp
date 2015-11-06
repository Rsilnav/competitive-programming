#include <iostream>

using namespace std;

int score(string s) {
	int num = 0;
	char c;
	int n;
	for (int i=0; i<s.size(); i++) {
		c = s.at(i);
		n = int(c);
		if (n >= 97 && n <= 122)
			num += n-96;
		if (n >= 65 && n <= 90)
			num += n-64;
	}
	int temp;
	while(num > 9) {
		temp = 0;
		while (num > 9) {
			temp = temp + num%10;
			num = num / 10;
		}
		num = temp + num;
	}
	return num;
}

int main() {
	ios_base::sync_with_stdio (false);
	string a, b;
	double scorea, scoreb;
	double ratio;
	while (getline(cin, a) && getline(cin, b)) {
		scorea = score(a);
		scoreb = score(b);
		if (scorea > scoreb)
			ratio = scoreb/scorea;
		if (scorea <= scoreb)
			ratio = scorea/scoreb;
		ratio *= 100;
		printf("%.2f %%\n", ratio);
	}
	return 0;
}

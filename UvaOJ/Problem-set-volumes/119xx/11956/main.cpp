#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	cin.ignore();
	string s;
	int memory[100];
	int pointer;
	for (int i=0; i<cases; i++) {
		for (int j=0; j<100; j++) {
			memory[j] = 0;
		}
		pointer = 0;
		getline(cin, s);
		char c;
		for (int j=0; j<s.size(); j++) {
			c = s.at(j);
			if (c == '>') {
				pointer++;
				if (pointer == 100)
					pointer = 0;
			}
			else if (c == '<') {
				pointer--;
				if (pointer == -1)
					pointer = 99;
			}
			else if (c == '+') {
				memory[pointer]++;
				if (memory[pointer] == 256)
					memory[pointer] = 0;
			}
			else if (c == '-') {
				memory[pointer]--;
				if (memory[pointer] == -1)
					memory[pointer] = 255;
			}
		}
		printf("Case %d:", i+1);
		for (int j=0; j<100; j++) {
			printf(" %02X", memory[j]);
		}
		printf("\n");
	}
	return 0;
}

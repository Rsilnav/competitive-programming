#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	int letters, lines;
	char c;
	int price;
	for (int i=0; i<cases; i++) {
		double totalCost = 0;
		int letters;
		cin >> letters;
		int cost[letters];
		char letter[letters];
		cin.ignore();
		string in;
		for (int j=0; j<letters; j++) {
			getline(cin, in);
			c = in.at(0);
			price = atoi(in.substr(2).c_str());
			cost[j] = price;
			letter[j] = c;
		}
		cin >> lines;
		cin.ignore();
		string line;

		for (int j=0; j<lines; j++) {
			getline(cin, line);
			for (int k=0; k<line.size(); k++) {
				c = line.at(k);
				for (int l=0; l<letters; l++) {
					if (c == letter[l]) {
						totalCost += cost[l];
						break;
					}
				}
			}
		}
		printf("%.2f$\n", totalCost/100);
		//cout << totalCost/100 << "$" << endl;
	}
	return 0;
}

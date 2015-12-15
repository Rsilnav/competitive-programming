#include <iostream>
#include <cmath>

using namespace std;

int fibIndex(int n) {
    double phi = (1+sqrt(5))/2;
		return round(log(n*sqrt(5))/log(phi))-1;
}

int main() {
	ios_base::sync_with_stdio (false);
	int cases, letters, max, ind;
	string phrase, parsedPhrase;
	char c;
	cin >> cases;

	for (int i=0; i<cases; i++) {
		cin >> letters;

		// Stores numbers
		int nums[letters];
		for (int j=0; j<letters; j++) {
			cin >> nums[j];
		}

		// Gets and cleans the crypted phrase
		cin.ignore();
		getline(cin, phrase);
		parsedPhrase = "";
		for (int a=0; a<phrase.size(); a++) {
			if (65 <= phrase.at(a) && phrase.at(a) <= 90) {
				parsedPhrase += phrase.at(a);
			}
		}

		// Translates numbers to their position in fib serie
		int order[letters];
		max = 0;
		for (int a=0; a<letters; a++) {
			order[a] = fibIndex(nums[a]);
			if (order[a] > max) {
				max = order[a];
			}
		}

		// Every non-used pos in the result array will be a space
		char result[max];
		for (int a=0; a<max; a++) {
			result[a] = ' ';
		}

		// Copies each char to its position in the result
		for (int a=0; a<letters; a++) {
			c = parsedPhrase.at(a);
			ind = order[a]-1;
			result[ind] = c;
		}

		// Outputs result
		for (int x=0; x<max; x++) {
			cout << result[x];
		}

		cout << endl;
	}
	return 0;
}

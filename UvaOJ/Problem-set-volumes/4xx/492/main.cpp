#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

bool isVowel(char c) {
  return find(vowels.begin(), vowels.end(), c) != vowels.end();
}



int main() {
	ios_base::sync_with_stdio (false);
  string line;
  while (getline(cin,line)) {
    string result = "";
    char c;
    string word = "";
    for (int i=0; i<line.size(); i++) {
      c = line.at(i);
      if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        word += c;
      }
      else if (word != ""){
        if (isVowel(word.at(0))) {
          result += word + "ay";
        }
        else {
          result += word.substr(1, word.size()) + word.at(0) + "ay";
        }
        word = "";
        result += c;
      }
      else {
        result += c;
      }
    }

    if (word != ""){
      if (isVowel(word.at(0))) {
        result += word + "ay";
      }
      else {
        result += word.substr(1, word.size()) + word.at(0) + "ay";
      }
      word = "";
    }

    cout << result << endl;
  }
	return 0;
}

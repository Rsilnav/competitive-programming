#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int cases;
	cin >> cases;
	cin.ignore();
	for (int i=0; i<cases; i++) {
		if(i>0) cout<<endl;
		cin.ignore();
		string s;
		getline(cin,s);
		int a[10000];

		int pos=1;
		for(int i=0; i<s.size(); ) {
			if( isdigit(s[i])) {
				int j=i;
				while( j!=s.size() && isdigit(s[j]))
					++j;
				int num=0;
				for(int k=i; k!=j; ++k)
					num=(num+s[k]-'0')*10;

				num=num/10;
				a[pos]=num;
				pos++;
				i=j;
			}
			else ++i;
		}

		string S[10000];
		string temp;
		getline(cin,temp);

		int pos1=1;
		for( int i=0; i!=temp.size(); ) {
			if( temp[i]!=' ') {
			int j=i;
			while( j!=temp.size() && temp[j]!=' ')
				++j;

			S[a[pos1]]=temp.substr(i,j-i);
			pos1++;

			i=j;
			}
			else i++;
		}

		for(int i=1; i<pos1; ++i)
			cout << S[i] <<endl;


	}

	return 0;

}

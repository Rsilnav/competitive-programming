#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	
	int duration;
	float down_pay, amount;
	int records;

	int month;
	float prct;

	float owed, value;

	while (true) {

		cin >> duration >> down_pay >> amount >> records;

		if (duration < 0)
			break;
		
		value = amount;
		owed = amount;

		month = 0;

		int lastmonth;
		int lastint;

		int nowmonth;
		int nowint;

		while (month < duration) {
			
			if (records > 0) {
				
			}


			month++;
		}

	}	


	return 0;
}

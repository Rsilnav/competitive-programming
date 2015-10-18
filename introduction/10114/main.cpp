#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int months, variations;
	double basePay, totalCost;

	while (cin >> months >> basePay >> totalCost >> variations) {
		if (months < 0)
			break;

		double carValue = totalCost + basePay;
		double monthlyPay = totalCost/basePay;
		double value = carValue;
		double owed = carValue;
		int payout = -1;
		float initialDepreciation;
		int month;
		cin >> month >> initialDepreciation;
		float lastDepreciation = initialDepreciation;
		int lastMonth = month;
		float depreciation;

		for (int i=1; i<variations; i++) {
			cin >> month >> depreciation;
			for (int j=lastMonth; j<month; j++) {
				value = value*(1-lastDepreciation);
				if (j==0) {
					owed = owed - basePay;
				}
				else {
					owed = owed - (totalCost/months);
				}
				if (owed < value && payout == -1) {
					payout = j;
				}
			}
			lastMonth = month;
			lastDepreciation = depreciation;
		}
		if (payout == -1) {
			for (int k=lastMonth; k<months, payout==-1; k++) {
				value = value*(1-lastDepreciation);
				if (k == 0) {
					owed = owed - basePay;
				}
				else {
					owed = owed - (totalCost/months);
				}

				if (owed < value && payout == -1) {
					payout = k;
				}
			}
		}
		cout << payout << " month";
		if (payout != 1)
			cout << "s";
		cout << endl;
	}
	return 0;
}

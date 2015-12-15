#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265

int main() {
	ios_base::sync_with_stdio (false);
	double l, w, h, theta;
	while (cin >> l >> w >> h >> theta) {
		double x1 = tan(theta * PI / 180);
		double x2 = tan((90-theta) * PI / 180);

		double area1 = x1*l*l/2;
		double area2 = x2*h*h/2;

		double result;

		if (area1 > area2) {
			result = area2 * w;
		}
		else {
			result = (l*h - area1) * w;
		}
		
		printf("%.3f mL\n", result);
	}
	return 0;
}

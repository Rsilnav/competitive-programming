#include <iostream>

using namespace std;

int main() {
	int h, m;
	float result;
	while(scanf("%d:%d", &h, &m)==2){
		if (h==0 && m==0)
			break;
		h = h % 12;
		result = h * 30 + m * 0.5 - m*6;
		if (result < 0)
			result *= -1;
		if (result > 180)
			result = 360 - result;
		printf("%.3f\n", result);
	}
	return 0;
}

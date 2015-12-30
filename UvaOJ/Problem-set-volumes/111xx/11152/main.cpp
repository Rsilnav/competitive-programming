#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio (false);

  const double PI = atan(1.0)*4;

	double a, b, c;

  double semiPerimeter, areaTriangle, areaBig, areaSmall;
  double radiusBig, radiusSmall;

  while (cin >> a >> b >> c) {

    semiPerimeter = (a+b+c)/2;
    areaTriangle = sqrt(semiPerimeter * (semiPerimeter-a) * (semiPerimeter-b) * (semiPerimeter-c));

    radiusSmall = areaTriangle/semiPerimeter;
    areaSmall = radiusSmall*radiusSmall*PI;

    radiusBig = (a*b*c)/sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c));
    areaBig = radiusBig*radiusBig*PI;

    printf("%.4f %.4f %.4f\n", areaBig-areaTriangle, areaTriangle-areaSmall, areaSmall);

  }

	return 0;
}

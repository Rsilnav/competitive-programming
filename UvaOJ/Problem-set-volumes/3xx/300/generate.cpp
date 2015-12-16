#include <iostream>

using namespace std;

/* Globals */
string months[] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

int main(int argc, char **argv)
{
cout << 730 << endl; // number of test cases
for (int i = 0; i < 2; i++) // year
{
for (int j = 0; j < 19; j++) // month
{
for (int k = 0; k < 20; k++) //day
{
if (k >= 5 && j == 18) break; // last month is s
cout << k << ". " << months[j] << " " << i << endl;
}
}
}
return 0;
}

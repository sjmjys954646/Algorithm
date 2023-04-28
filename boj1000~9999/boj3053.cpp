#include <iostream>
#define PI 3.14159265358979323846

using namespace std;

int main()
{
	double R;

	cin >> R;
	cout.setf(ios::fixed);
	cout.precision(6);
	cout << R*R*PI << '\n';
	cout << R*R*2 ;

	return 0;
}
#include <iostream>
#include <math.h>
using namespace std;

double FindDis(double x1, double y1, double x2, double y2);

int main()
{
	double x1, y1, x2, y2, r1, r2;
	int num;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		if (x1 == x2 && y1 == y2 && r1 == r2)
			cout << "-1";
		else if (r1 + r2<dis || fabs(r1 - r2)>dis)
			cout << '0';
		else if (r1 + r2 == dis || fabs(r1 - r2) == dis)
			cout << '1';
		else
			cout << '2';

		if (i != num - 1)
			cout << '\n';
		dis = 0;
	}


	return 0;
}

double FindDis(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
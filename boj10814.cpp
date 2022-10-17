#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	string a;
	int turn;
};

bool cmp(const Point& p1, const Point& p2);

int main()
{
	int N;
	Point p;

	cin >> N;

	vector<Point> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].x >> vec[i].a;
		vec[i].turn = i;
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].x << " " << vec[i].a << "\n";
	}

	return 0;
}

bool cmp(const Point& p1, const Point& p2)
{
	if (p1.x < p2.x)
		return true;
	else if (p1.x == p2.x)
		if (p1.turn < p2.turn) 
			return true;
		else 
			return false;	
	else
		return false;
}
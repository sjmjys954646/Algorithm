#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point 
{
	int x;
	int y;
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
		cin >> vec[i].x >> vec[i].y;
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].x << " " << vec[i].y << "\n";
	}

	return 0;
}

bool cmp(const Point& p1, const Point& p2)
{
	if (p1.y < p2.y)
		return true;
	else if (p1.y == p2.y)
		return p1.x < p2.x;
	else
		return false;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <sstream>
#include <string.h>
#include <queue>
using namespace std;

const int INF = 987654321;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int testcase;
	cin >> testcase;

	for (int i = 1; i <= testcase; i++)
	{
		vector<int> v;

		for(int i = 0;i<3;i++)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		cout << "Case #" << i << ": ";
		if (v[0] + v[1] > v[2])
		{
			if (v[0] == v[1] && v[1] == v[2])
				cout << "equilateral";
			else if (v[0] == v[1] || v[1]==v[2] || v[0] == v[2])
				cout << "isosceles";
			else
				cout << "scalene";

		}
		else
		{
			cout << "invalid!";
		}
		cout << "\n";
		
	}

	return 0;
}

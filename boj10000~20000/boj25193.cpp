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

	int N;
	string tmp;

	cin >> N;

	cin >> tmp;

	int ans = 0;
	int p = 0;
	for(int i = 0;i<tmp.size();i++)
	{
		if (tmp[i] == 'C')
			p++;
	}
	int k = N - p;
	k++;

	int t = p / k;
	int u = p % k;

	if (u != 0)
		t++;

	if (p == 0)
		cout << 0;
	else
		cout << t;

	return 0;
}

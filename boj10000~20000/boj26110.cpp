#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;

string tmp;

int check(int a, int b, int depth)
{
	if (depth >= 4)
		return 987654321;

	int ret = 987654321;
	while (true)
	{
		if (a >= b)
		{
			ret = depth;
			return ret;
		}

		if (tmp[a] != tmp[b])
		{
			ret = min(check(a+1, b, depth + 1), check(a, b-1, depth + 1));
			break;
		}
		else
		{
			a++;
			b--;
		}
	}
	return ret;
}

int main()
{
	cin >> tmp;

	int p  = check(0, tmp.size() - 1, 0);
	if (p == 987654321)
		cout << -1;
	else
		cout << p;
	
	return 0;
}
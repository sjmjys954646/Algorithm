#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <string.h>
using namespace std;

int T;
int N;
int prefix[1002];
int v[1002];
int tmp;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		memset(v, 0, sizeof(v));
		memset(prefix, 0, sizeof(prefix));

		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			cin >> tmp;
			v[i] = tmp;
			prefix[i] = prefix[i - 1] + tmp;
		}

		//for (int i = 0; i <= N; i++)
		//	cout << prefix[i] << " ";

		int ans = -987654321;
		for (int i = 0; i <= N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				ans = max(ans, prefix[i] - prefix[j]);
			}
		}
		cout << ans << '\n';
	}
    

	return 0;
}

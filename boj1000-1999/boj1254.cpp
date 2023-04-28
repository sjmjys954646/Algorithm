// freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <bitset>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 987654321;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string tmp;
	string reversetmp;

	cin >> tmp;
	reversetmp = tmp;
	reverse(reversetmp.begin(), reversetmp.end());

	char ff = reversetmp[0];
	int ans = INF;

	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == ff)
		{
			bool same = true;
			int index = i;
			int reverseindex = 0;
			while (true)
			{
				if (index == tmp.size())
					break;

				if (reversetmp[reverseindex] == tmp[index])
				{
					index++;
					reverseindex++;
					continue;
				}

				same = false;
				break;
			}

			if (same)
			{
				ans = min(ans, (int)(tmp.size() * 2 - (tmp.size() - i ) ));
			}
		}
	}

	cout << ans;



	return 0;
}
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char> st;

	string s;
	string p;

	cin >> s;
	cin >> p;

	char pFin = *(p.end()-1);

	for (int i = 0; i < s.length(); i++)
	{
		st.push(s[i]);

		if (i < p.length() - 1)
			continue;

		if (s[i] == pFin)
		{
			string tmp = "";
			int pIndex = p.length() - 1;
			
			bool boom = true;
			while (true)
			{
				if (pIndex < 0)
					break;

				char ctmp = st.top();
				if (ctmp != p[pIndex])
				{
					boom = false;
					break;
				}
				st.pop();
				tmp += ctmp;
				pIndex--;
			}

			if (!boom)
			{
				reverse(tmp.begin(), tmp.end());
				for (int j = 0; j < tmp.size(); j++)
				{
					st.push(tmp[j]);
				}
			}
		}
	}

	string ans = "";

	while (!st.empty())
	{
		char p = st.top();
		ans += p;
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	if (ans.size() == 0)
		cout << "FRULA";
	else
		cout << ans;


	return 0;
}
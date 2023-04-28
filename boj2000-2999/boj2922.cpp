#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

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


string tmp;
long long ans = 0;
deque<int> recent;
// 1 모음 0 자음

long long dfs(int index, int hasL)
{
	long long ret = 0;
	if (recent.size() == 3)
	{
		int sum = 0;
		for (auto i : recent)
			sum += i;
		if (sum == 3 || sum == 0)
			return 0;
	}

	if (index == tmp.size() )
	{
		if (hasL)
			return 1;
		else
			return 0;
	}

	char t = tmp[index];
	if (t == 'L')
		hasL = 1;
	deque<int> tmpV = recent;

	if (t == '_')
	{
		if (recent.size() == 3)
		{
			recent.pop_front();
		}
		recent.push_back(1);
		ret += dfs(index + 1,hasL)*5;

		recent = tmpV;
		if (recent.size() == 3)
		{
			recent.pop_front();
		}
		recent.push_back(0);
		ret += dfs(index + 1, hasL)*20;

		recent = tmpV;
		if (recent.size() == 3)
		{
			recent.pop_front();
		}
		recent.push_back(0);
		ret += dfs(index + 1, 1);
	}
	else
	{
		int add = 0;
		if (t == 'A' || t == 'E' || t == 'I' || t == 'O' || t == 'U')
		{
			add = 1;
		}

		if (recent.size() == 3)
		{
			recent.pop_front();
		}
		recent.push_back(add); 
		ret += dfs(index + 1, hasL);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tmp;

	cout << dfs(0, 0);

	return 0;
}
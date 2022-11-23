// freopen("input.txt", "r", stdin);
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

vi v;
int visited[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 0;
	while(true)
	{
		if (v.size() > 1000003)
			break;

		num++;
		string tmp = to_string(num);

		bool pos = true;
		memset(visited, 0, sizeof(visited));

		for (int j = 0; j < tmp.size(); j++)
		{
			if (visited[tmp[j] - '0'])
			{
				pos = false;
				break;
			}
			visited[tmp[j] - '0'] = 1;
		}
		if (pos)
			v.push_back(num);
	}
	while (true)
	{
		int tmp;
		cin >> tmp;
		if (!tmp)
			break;
		cout << v[tmp - 1]<<"\n";
	}

	return 0;
}
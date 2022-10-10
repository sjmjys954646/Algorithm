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

	int N;
	vi v;

	while (true)
	{
		string a = "";
		string b = "";
		int index = 0;
		int zerosum = 0;
		v.clear();

		cin >> N;

		if (!N)
			break;

		for (int i = 0; i < N; i++)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
			if (tmp == 0)
				zerosum++;
		}

		sort(v.begin(), v.end());

		if (zerosum == 1)
		{
			swap(v[0], v[2]);
		}
		else if(zerosum >= 2)
		{
			swap(v[0], v[zerosum]);
			swap(v[1], v[zerosum+1]);
		}
		

		while (!v.empty())
		{
			if (index == 0)
			{
				a += to_string(v.back());
				v.pop_back();
				index = 1;
			}
			else
			{
				b += to_string(v.back());
				v.pop_back();
				index = 0;
			}
		}

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());


		cout << stoi(a) + stoi(b) << "\n";
	}

	return 0;
}
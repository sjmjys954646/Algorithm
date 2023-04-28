#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

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


int testcase;
ll N, K;

ll pow(int base, int exp)
{
	ull tmp = 1;

	while (true)
	{
		if (exp <= 0)
			break;

		tmp = tmp << 1;

		exp--;
	}

	return tmp;
}

void Hanoi(ll num, ll start, ll by, ll to, ll mok)
{
	if (num == 1)
	{
		cout << start << " " << to << "\n";
		return;
	}
	else
	{
		if (mok <= pow(2, num - 1) - 1 )
		{
			Hanoi(num - 1, start, to, by, mok);
		}
		else if (mok > pow(2, num - 1)  )
		{
			Hanoi(num - 1, by, start, to, mok - pow(2, num - 1) );
		}
		else
		{
			cout << start << " " << to << "\n";
			return;
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N >> K;

	Hanoi(N, 1, 2, 3, K);


	return 0;
}
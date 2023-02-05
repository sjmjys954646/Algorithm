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

const int INF = 9876543210;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int testcase;

    cin >> testcase;

    while (testcase--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        a %= d;
        b %= d;
        c %= d;

        if ((a % d == 0 && b % d == 0) ||
            (a % d == 0 && c % d == 0) ||
            (b % d == 0 && c % d == 0)
            )
        {
            cout << 1 << "\n";
        }
        else
            cout << 0 << "\n";
    }
    

	return 0;
}
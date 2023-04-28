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

    int a;
    cin >> a;

    if (a >= 100)
    {
        string tmp = to_string(a);
        if (tmp.substr(0, 2) == "10")
        {
            cout << 10 + a % 100;
        }
        else
            cout << a / 100 + 10;
    }
    else
    {
        cout << a / 10 + a % 10;
    }
    

	return 0;
}
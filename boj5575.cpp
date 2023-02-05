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

    int a, b, c, d, e, f;
    int n = 3;

    while (n--)
    {
        cin >> a >> b >> c >> d >> e >> f;
        int k = (d - a) * 3600 + (e - b) * 60 + (f-c);
        cout << k / 3600 << " ";
        k %= 3600;
        cout << k / 60 << " ";
        k %= 60;
        cout << k << "\n";
    }
    

	return 0;
}
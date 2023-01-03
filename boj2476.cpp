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

int N;
int ans = -1;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == b && b == c)
        {
            ans = max(ans, 10000 + a * 1000);
        }
        else if (a == b || b == c || c == a)
        {
            int p = a == b ? a : c;
            ans = max(ans, 1000 + p * 100);
        }
        else
        {
            ans = max(ans, max({ a,b,c }) * 100);
        }
    }

    cout << ans;
    

    return 0;
}
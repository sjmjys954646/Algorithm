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

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string tmp;
        string tmp2;

        cin >> tmp >> tmp2;

        int x1 = 0, y1 = 0;
        int dif = 0;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != tmp2[i])
                dif++;
            if (tmp[i] == '1')
                x1++;
            if (tmp2[i] == '1')
                y1++;
        }
        int ans = 0;
        int t = abs(y1 - x1);
        ans += t;
        dif -= t;
        ans += dif / 2;
        cout << ans << "\n";
    }
   

    return 0;
}
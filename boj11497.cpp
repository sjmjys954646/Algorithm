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

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;

    cin >> testcase;

    while (testcase--)
    {
        v.clear();

        int N;
        int tmp;
        int ans = -1;

        cin >> N;

        rep(i, N)
        {
            cin >> tmp;
            v.push_back(tmp);
        }

        sort(v.begin(), v.end(),greater<>());

        for (int i = 1; i < N; i++)
        {
            if (i == 1)
                ans = max(ans, v[1] - v[0]);
            else
                ans = max(ans, v[i - 2] - v[i]);
        }
        ans = max(ans, v[N-2]-v[N - 1]);

        cout << ans << "\n";
    }
    


    return 0;
}
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

ll N, M, L, A;
long long B;
vector<ll> v;
vector<ll> vv;
ll vprefix[100002];
ll vvprefix[100002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> B >> A;

    ll tmp;

    rep(i, N)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());


    for (int i = 1;i<=N;i++)
    {
        vprefix[i] = vprefix[i - 1] + v[i-1];
        vv.push_back(v[i-1] / 2);
        vvprefix[i] = vvprefix[i - 1] + v[i - 1] / 2;
    }

    int hubo = 0;
    for (int i = 1; i <= N; i++)
    {
        ll sum = 0;
        if (i <= A)
        {
            sum += vvprefix[i] - vvprefix[0];
            if (B >= sum)
                hubo = max(hubo, i);
        }
        else
        {
            sum += vprefix[i - A] - vprefix[0];
            sum += vvprefix[i] - vvprefix[i - A];
            if (B >= sum)
                hubo = max(hubo, i);
        }
    }
    cout << hubo;
	

	return 0;
}
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

    int N, K;
    vi v;
    int tmp;

    cin >> N >> K;  

    rep(i, N)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), greater<>());
    
    int sum = 0;
    for (int i = 0; i < K; i++)
    {
        sum += v[i];
    }
    
    cout << sum - K*(K-1)/2;

	return 0;
}
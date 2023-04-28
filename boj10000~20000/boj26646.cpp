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

int arr[50002];

int main()
{
    int N;

    cin >> N;

    ll ans = 0;
    

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < N; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            ans += (arr[i] * arr[i] * 4);
        }
        else
        {
            ans += abs(arr[i] - arr[i - 1]) * abs(arr[i] - arr[i - 1])  + (arr[i] + arr[i - 1]) * (arr[i] + arr[i - 1]);
        }
    }

    cout << ans;

    return 0;
}
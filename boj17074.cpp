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
                

int N;
int arr[100002];
int num = 0;
int pos = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N;

    rep1(i, N)
    {
        cin >> arr[i];
    }
    arr[0] = -INF;
    arr[N + 1] = INF;

    for (int i = 1; i <= N; i++)
    {
        if (arr[i-1] > arr[i])
        {
            pos = i;
            num++;
        }
    }

    if (num > 1)
    {
        cout << 0;
    }
    else if (num == 0)
    {
        cout << N;
    }
    else
    {
        int sum = 0;
        if (arr[pos - 2] <= arr[pos])
            sum++;
        if (arr[pos - 1] <= arr[pos + 1])
            sum++;
        cout << sum;
    }


    return 0;
}
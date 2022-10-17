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

int testcase;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string tmp;
    int ans = 0;
    int arr[27];

    memset(arr, 0, sizeof(arr));

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        int numl = tmp.length();
        for (int j = 0; j < numl; j++)
        {
            arr[tmp[j] - 'A'] += pow(10, numl - j - 1);
        }
    }

    sort(arr, arr + 27);

    int index = 9;
    for (int i = 26; i >= 0; i--)
    {
        ans += arr[i] * index;
        index--;
    }

    cout << ans;

    return 0;
}
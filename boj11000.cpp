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

vector<pii> v;
int N;
int a, b;
int ans = 0;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int,vector<int>,greater<int>> pq;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        v.push_back({ a,b });
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        int curF = v[i].first;
        int curE = v[i].second;

        if (pq.empty())
        {
            pq.push(curE);
            ans++;
            continue;
        }

        if (pq.top() > curF)
        {
            ans++;
            pq.push(curE);
        }
        else
        {
            pq.pop();
            pq.push(curE);
        }
    }
    
    cout << ans;

    return 0;
}
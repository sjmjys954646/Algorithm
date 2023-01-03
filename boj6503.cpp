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
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    while (true)
    {
        int N;
        string tmp;
        int ans = 0;
        int left = -1, right = -1;
        int visited[150] = { 0, };
        int curUse = 0;

        cin >> N;
        cin.ignore();
        if (!N)
            break;

        getline(cin, tmp);

        while (left <= right)
        {
            if (curUse < N || (curUse == N && visited[(int)tmp[right + 1]]  > 0))
            {
                right++;
                visited[(int)tmp[right]] += 1;
                curUse += visited[(int)tmp[right]] == 1 ? 1 : 0;
            }
            else
            {
                left++;
                visited[(int)tmp[left]] -= 1;
                curUse -= visited[(int)tmp[left]] == 0 ? 1 : 0;
            }

            ans = max(right - left, ans);

            if (right == tmp.size() - 1)
                break;
        }
        cout << ans << '\n';
    }


    

    return 0;
}
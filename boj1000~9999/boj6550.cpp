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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        string tmp;
        string query;

        cin >> tmp >> query;
        if (cin.eof() == true)
            break;

        bool check = false;
        int index = 0;

        for (int i = 0; i < query.length(); i++)
        {
            if (index == tmp.length())
            {
                break;
            }

            if (query[i] == tmp[index])
            {
                index++;
            }
        }

        if (index == tmp.length())
        {
            check = true;
        }
        
        if (check)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
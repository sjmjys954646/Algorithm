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

void debug(stack<pair<long long, long long>> st)
{
    while(!st.empty())
    {
        pair<long long, int> p = st.top();
        st.pop();
        cout << p.first << " " << p.second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    stack<pair<long long, long long>> st;
    long long tmp;
    long long ans = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if (st.empty())
        {
            st.push({ tmp, 1 });
            continue;
        }

        ll sz = 1;
        if (st.top().first < tmp)
        {
            while (true)
            {
                if (st.empty())
                    break;

                if (st.top().first >= tmp)
                    break;

                ans+=st.top().S;

                st.pop();
            }

        }

        if (st.empty())
        {
            st.push({ tmp, 1 });
            continue;
        }

        if(st.top().first == tmp)
        {
            ans += st.top().S;
            sz += st.top().S;
            st.pop();
        }

        if (st.size() > 0)
            ans++;


        st.push({ tmp,sz });

        /*cout << i << " : " << "\n";
        debug(st);
        cout << "ans : " << ans << "\n";*/

    }


    cout << ans;

    return 0;
}
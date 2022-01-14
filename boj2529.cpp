//freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>

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

int k;
vector<char> arr;
vi hubo;
bool visited[10];
vector<string> realHubo;

bool cal()
{
    bool ok = true;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] == '<' && hubo[i] > hubo[i + 1])
        {
            ok = false;
            break;
        }
        else if (arr[i] == '>' && hubo[i] < hubo[i + 1])
        {
            ok = false;
            break;
        }
    }

    return ok;
}

void select(int index)
{
    if (index == k + 1)
    {
        if (cal())
        {
            string tmp = "";
            for (int i = 0; i < k + 1; i++)
            {
                tmp += (hubo[i] + '0');
            }
            realHubo.pb(tmp);
        }

        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (visited[i] == true)
            continue;

        hubo.pb(i);
        visited[i] = true;
        select(index + 1);
        hubo.pop_back();
        visited[i] = false;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    char tmp;

    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        arr.pb(tmp);
    }
    select(0);

    sort(realHubo.begin(), realHubo.end());

    cout << realHubo.back() << "\n"
         << realHubo.front();

    return 0;
}
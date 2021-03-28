//freopen("input.txt", "r", stdin);
//2028kb 4ms
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

struct Trie
{
    Trie *next[26];
    bool finish;
    int childCnt;

    Trie()
    {
        fill(next, next + 26, nullptr);
        finish = false;
        childCnt = 0;
    }
    ~Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            if (next[i])
                delete (next[i]);
        }
    }
    void insert(const char *key)
    {
        if (*key == '\0')
        {
            finish = true;
            return;
        }
        int num = *key - 'a';
        if (!next[num])
        {
            childCnt++;
            next[num] = new Trie();
        }

        next[num]->insert(key + 1);
        return;
    }
    int find(const char *key, int cnt)
    {
        if (*key == '\0')
        {
            return cnt;
        }
        if (childCnt > 1 || finish)
            cnt++;
        int num = *key - 'a';
        return next[num]->find(key + 1, cnt);
    }
};

int t, n;
char a[100001][82];

int main()
{
    freopen("input.txt", "r", stdin);

    while (scanf("%d", &n) != EOF)
    {
        Trie trie;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", &a[i]);
            trie.insert(a[i]);
        }

        int cnt = 0;

        if (trie.childCnt == 1)
            cnt += n;

        for (int i = 0; i < n; i++)
            cnt += trie.find(a[i], 0);

        printf("%.2lf\n", (double)cnt / n);
    }

    return 0;
}
//freopen("input.txt", "r", stdin);
//2016kb 4ms
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
const int ALPHABETS = 26;

int char_to_index(char c)
{
    return c - 'A';
}

int N, M;

struct Trie
{
    Trie *next[26];
    bool finish;

    Trie()
    {
        fill(next, next + 26, nullptr);
        finish = false;
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
            next[num] = new Trie();

        next[num]->insert(key + 1);
        return;
    }
    bool find(const char *key)
    {
        if (*key == '\0')
        {
            return finish;
        }
        int num = *key - 'a';
        if (!next[num])
            return false;
        return next[num]->find(key + 1);
    }
};

int main()
{
    freopen("input.txt", "r", stdin);

    Trie *root = new Trie();

    char tmp[10050];
    int ans = 0;
    scanf("%d %d", &N, &M);

    rep(i, N)
    {
        scanf("%s", tmp);
        root->insert(tmp);
    }
    rep(i, M)
    {
        scanf("%s", tmp);
        if (root->find(tmp))
            ans++;
    }

    printf("%d", ans);

    return 0;
}
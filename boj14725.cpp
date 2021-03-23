//freopen("input.txt", "r", stdin);
//6636kb 48ms
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

struct Node
{
    map<string, Node *> data;
};

void dfs(Node *cur, int depth)
{
    map<string, Node *>::iterator iter;
    for (iter = cur->data.begin(); iter != cur->data.end(); iter++)
    {
        for (int i = 0; i < depth; i++)
        {
            cout << "--";
        }
        cout << iter->first << '\n';

        dfs(iter->second, depth + 1);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    Node *head = new Node();
    Node *cur;

    for (int i = 0; i < N; i++)
    {
        int depth;
        cin >> depth;
        string str;

        cur = head;

        for (int j = 0; j < depth; j++)
        {
            cin >> str;

            if (cur->data.find(str) == cur->data.end())
            {
                Node *newNode = new Node();
                cur->data.insert({str, newNode});
                cur = newNode;
            }
            else
            {
                cur = cur->data[str];
            }
        }
    }

    dfs(head, 0);

    return 0;
}
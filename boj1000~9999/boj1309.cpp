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

int N;
int cache[100002][3];

int main()
{
    scanf("%d", &N);

    cache[0][0] = 1;
    cache[0][1] = 1; 
    cache[0][2] = 1;
    
    for (int i = 1; i <= N; i++)
    {
        cache[i][0] = (cache[i - 1][0] + cache[i - 1][1] + cache[i - 1][2]) % 9901;
        cache[i][1] = (cache[i - 1][0] + cache[i - 1][2]) % 9901;
        cache[i][2] = (cache[i - 1][0] + cache[i - 1][1]) % 9901;
    }
    printf("%d",(cache[N-1][0] + cache[N-1][1] + cache[N-1][2]) % 9901);

    return 0;
}
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
/*
1. ���� ����
2. N�ʵ��� ������
3. ��� ���� ��ȸ�Ѵ�
N^3Ǯ�̰� �Ǵµ�  1�� 3���� ��ġ���� �غ���

���� ��Ƴ�

���� : 
https://github.com/ISKU/Algorithm/blob/6697e269afc4e8385f4ab81737996e2ef786c547/BOJ/15980/Main.java
*/
int M, N;
vector<pair<char, string>> birds;
int psum[2003] = {
    0,
};

int main()
{

    vector<pair<int, int>> ansbird;

    scanf("%d %d", &N, &M);

    rep(i, N)
    {
        string tmp;
        char direction;
        cin >> direction >> tmp;
        birds.push_back({direction, tmp});
        rep(j, M)
        {
            if (tmp[j] == '0')
                continue;

            if (direction == 'L')
                psum[j + 1]++;
            else
                psum[j + 1]--;
        }
    }
    for (int i = 1; i <= M; i++)
    {
        psum[i] = psum[i - 1] - psum[i];
    }

    int idx = 0;
    int ans = INF;
    for (int i = 0; i < N; i++)
    {
        int p = 0;
        int maxi = 0;

        for (int j = 0; j < M; j++)
        {
            if (birds[i].S[j] == '1')
            {
                if (birds[i].F == 'L')
                    p++;
                else
                    p--;
            }
            maxi = max(maxi, abs(psum[j + 1] + p));
        }

        if (ans > maxi)
        {
            ans = maxi;
            idx = i;
        }
    }

    printf("%d\n%d", idx + 1, ans);

    return 0;
}
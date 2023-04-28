// freopen("input.txt", "r", stdin);
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

int testcase;
int N;

void prof(int num)
{
    if (num == 0)
    {
        for (int i = 0;i < N;i++)
            cout << "____";
        cout << "\"재귀함수가 뭔가요?\"\n";
        for (int i = 0; i < N; i++)
            cout << "____";
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        for (int i = 0; i < N; i++)
            cout << "____";
        cout << "라고 답변하였지.\n";
        return;
    }
    for (int i = 0; i < N - num; i++)
        cout << "____";
    cout << "\"재귀함수가 뭔가요?\"\n";
    for (int i = 0; i < N - num; i++)
        cout << "____";
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    for (int i = 0; i < N - num; i++)
        cout << "____";
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    for (int i = 0; i < N - num; i++)
        cout << "____";
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    prof(num - 1);
    for (int i = 0; i < N - num; i++)
        cout << "____";
    cout << "라고 답변하였지.\n";

}

int main() 
{
    cin >> N;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

    prof(N);
    
}
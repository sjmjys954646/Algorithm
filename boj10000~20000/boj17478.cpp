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
        cout << "\"����Լ��� ������?\"\n";
        for (int i = 0; i < N; i++)
            cout << "____";
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        for (int i = 0; i < N; i++)
            cout << "____";
        cout << "��� �亯�Ͽ���.\n";
        return;
    }
    for (int i = 0; i < N - num; i++)
        cout << "____";
    cout << "\"����Լ��� ������?\"\n";
    for (int i = 0; i < N - num; i++)
        cout << "____";
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    for (int i = 0; i < N - num; i++)
        cout << "____";
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    for (int i = 0; i < N - num; i++)
        cout << "____";
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    prof(num - 1);
    for (int i = 0; i < N - num; i++)
        cout << "____";
    cout << "��� �亯�Ͽ���.\n";

}

int main() 
{
    cin >> N;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

    prof(N);
    
}
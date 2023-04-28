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
#include <typeinfo>
#include <cmath>

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

int number = 10000000;
int arr[10000002];

void primeNumberSieve() {

	for (int i = 2; i <= number; i++) 
	{
		arr[i] = i;
	}

	for (int i = 2; i <= number; i++) 
	{
		if (arr[i] == 0) continue;
		
		for (int j = 2 * i; j <= number; j += i) 
		{
			arr[j] = 0;
		}
	}

}

bool check(int num)
{
	if (arr[num] == 0)
		return false;

	bool pos = true;

	string k = to_string(num);

	for (int i = 0; i < k.size(); i++)
	{
		if (k[i] != k[k.size() - 1 - i])
			return false;
	}


	return pos;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	primeNumberSieve();

	int N;

	cin >> N;

	while (true)
	{
		if (check(N))
			break;

		N++;
	}

	cout << N;

	return 0;
}

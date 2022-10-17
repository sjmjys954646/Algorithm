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


int N, C, M;
struct Parcel {
	int sendNum;
	int recieveNum;
	int weight;
};

bool compare(Parcel a, Parcel b) 
{
	return a.recieveNum < b.recieveNum;
}

int ParcelWeight[2002] = {0,};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> C;
	cin >> M;
	vector<Parcel> v;

	rep(i, M)
	{
		Parcel t;
		cin >> t.sendNum >> t.recieveNum >> t.weight;
		v.push_back(t);
	}

	sort(v.begin(), v.end(), compare);

	int ans = 0;
	for (int i = 0; i < M; i++) {
		int maxWeight = 0;
		for (int j = v[i].sendNum; j < v[i].recieveNum;j++) {
			maxWeight = max(maxWeight, ParcelWeight[j]);
		}
		int left = min(v[i].weight, C - maxWeight);
		for (int j = v[i].sendNum; j < v[i].recieveNum;j++) {
			ParcelWeight[j] += left;
		}
		ans += left;
	}
	cout << ans;

	return 0;
}

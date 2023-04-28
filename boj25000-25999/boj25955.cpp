#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int N;
map<char, int> m;
map<int, char> mrev;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second > b.second;
}

int main()
{
	vector<pair<int, int>> v;
	vector<pair<int, int>> bef;
	vector<pair<int, int>> hubo;

	cin >> N;

	m['B'] = 0;
	m['S'] = 1;
	m['G'] = 2;
	m['P'] = 3;
	m['D'] = 4;

	mrev[0] = 'B';
	mrev[1] = 'S';
	mrev[2] = 'G';
	mrev[3] = 'P';
	mrev[4] = 'D';

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;

		pair<int, int> k = { m[tmp[0]], stoi(tmp.substr(1)) };
		v.push_back(k);
		bef.push_back(k);
	}
	sort(v.begin(), v.end(),cmp);


	for (int i = 0; i < N; i++)
	{
		if (bef[i] != v[i])
			hubo.push_back(v[i]);
	}

	if (hubo.size() == 0)
		cout << "OK";
	else
		cout << "KO\n" << mrev[hubo[0].first] << hubo[0].second << " " << mrev[hubo[1].first] << hubo[1].second;

	return 0;
}

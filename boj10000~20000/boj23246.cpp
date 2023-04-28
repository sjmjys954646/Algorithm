#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;


struct Player {
	int score;
	int addscore;
	int back;
};

bool cmp(Player a, Player b)
{
	if (a.score != b.score)
		return a.score < b.score;
	else if (a.addscore != b.addscore)
		return a.addscore < b.addscore;
	else
		return a.back < b.back;
}

int N;
vector<Player> v;

int main()
{
	int a, b, c, d;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		Player k;
		cin >> a >> b >> c >> d;
		k.score = b * c * d;
		k.addscore = b + c + d;
		k.back = a;

		v.push_back(k);
	}

	sort(v.begin(), v.end(),cmp );

	for (int i = 0; i < 3; i++)
		cout << v[i].back << " ";
	

	return 0;
}

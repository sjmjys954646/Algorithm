// freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

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

int sHour;
int sMin;
int eHour;
int eMin;
int qHour;
int qMin;

pair<int, int> converter(string tmp)
{
	return { (tmp[0] - '0') * 10 + (tmp[1] - '0') ,(tmp[3] - '0') * 10 + (tmp[4] - '0') };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S, E, Q;
	string tmp;
	map<string, int> m;
	set<string> s;

	cin >> S >> E >> Q;
	
	pii Sc = converter(S);
	sHour = Sc.first;
	sMin = Sc.second;
	Sc = converter(E);
	eHour = Sc.first;
	eMin = Sc.second;
	Sc = converter(Q);
	qHour = Sc.first;
	qMin = Sc.second;

	cin.ignore();

	while (true)
	{
		getline(cin, tmp);

		if (cin.eof())
			break;

		Sc = converter(tmp.substr(0, 5));
		int Hour = Sc.first;
		int Min = Sc.second;

		string Name = tmp.substr(6);
		
		if (Hour < sHour || (Hour == sHour && Min <= sMin ))
		{
			m[Name]++;
		}

		if (
			( Hour > eHour || (Hour == eHour && Min >= eMin) )
			&&
			( Hour < qHour || (Hour == qHour && Min <= qMin) )
		)
		{
			if (m.find(Name) != m.end())
				s.insert(Name);
		}

	}
	cout << s.size();

	return 0;
}
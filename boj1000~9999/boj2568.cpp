#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <stack>
using namespace std;

int N;
vector<pair<int,int>> v;
int conv[500200];
int rev[500200];
vector<int> lis;
int ansV[500200];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

    cin >> N;
    int A, B;

    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        v.push_back({ A,B });
        conv[A] = B;
        rev[B] = A;
    }

	sort(v.begin(), v.end());

	lis.push_back(-987654321);

	for (int i = 0; i < N; i++) 
	{
		if (lis.back() < v[i].second) 
		{
			lis.push_back(v[i].second);
			ansV[i] = lis.size() - 1;
		}
		else 
		{
			auto it = lower_bound(lis.begin(), lis.end(), v[i].second);
			*it = v[i].second;
			ansV[i] = it - lis.begin();
		}
	}
	lis.erase(lis.begin());

	cout << N - lis.size() << "\n";
	
	int p = lis.size();
	stack<int> st;

	for (int i = 1; i <= N; i++)
	{
		if (ansV[N - i] == p)
			p--;
		else
			st.push(v[N - i].first);
	}

	while (!st.empty())
	{
		cout << st.top() << "\n";
		st.pop();
	}

	return 0;
}

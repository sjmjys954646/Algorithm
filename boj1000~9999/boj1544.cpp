#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;


int main()
{
	int N;
	cin >> N;

	set<string> s;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;

		bool find = false;
		for (int j = 0; j < tmp.size(); j++)
		{
			//있는지 확인 없으면 변경
			if (s.find(tmp) == s.end())
			{
				string k = tmp.substr(0,1);
				string newTmp = tmp.substr(1);
				newTmp.append(k);
				tmp = newTmp;
			}
			else
			{
				find = true;
				break;
			}
		}

		if (!find)
		{
			s.insert(tmp);
		}
	}

	cout << s.size();

	return 0;
}
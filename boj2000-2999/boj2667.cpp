#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int main(void)
{
	int num;
	
	cin >> num;

	vector<int> HouseNum;
	int Check[26][26];
	int HousePlace[26][26];
	queue<pair<int, int> > q;
	int housesum = 0;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			scanf("%1d", &HousePlace[i][j]);
			Check[i][j] = 0;
		}
	}


	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (Check[i][j] == 0)
			{
				if (HousePlace[i][j] == 0)
				{
					Check[i][j] = 1;
				}
				else
				{
					q.push(make_pair(i, j));

					while (!q.empty())
					{
						int frontI = q.front().first;
						int frontJ = q.front().second;
						q.pop();
						
						if (Check[frontI][frontJ] == 0)
						{
							housesum++;
							Check[frontI][frontJ] = 1;
						}
						if (HousePlace[frontI-1][frontJ] == 1 && Check[frontI - 1][frontJ] == 0 && frontI>0)
						{
							q.push(make_pair(frontI - 1, frontJ));
							Check[frontI - 1][frontJ] = 1;
							housesum++;
						}
						if (HousePlace[frontI + 1][frontJ] == 1 && Check[frontI + 1][frontJ] == 0 && frontI<num-1)
						{
							q.push(make_pair(frontI + 1, frontJ));
							Check[frontI + 1][frontJ] = 1;
							housesum++;
						}
						if (HousePlace[frontI][frontJ - 1] == 1 && Check[frontI][frontJ - 1] == 0 && frontJ > 0)
						{
							q.push(make_pair(frontI, frontJ -1));
							Check[frontI][frontJ - 1] = 1;
							housesum++;

						}
						if (HousePlace[frontI][frontJ + 1] == 1 && Check[frontI][frontJ + 1] == 0 && frontJ < num-1)
						{
							q.push(make_pair(frontI, frontJ + 1));
							Check[frontI][frontJ + 1] = 1;
							housesum++;
						}
					}			
					HouseNum.push_back(housesum);
					housesum = 0;
				}
			}
		}
	}

	sort(HouseNum.begin(), HouseNum.end());

	cout << HouseNum.size()<<"\n";
	for (int i = 0; i < HouseNum.size(); i++)
	{
		cout << HouseNum[i] << "\n";
	}

	return 0;
}
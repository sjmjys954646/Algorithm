#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int arr[51][51];
int N, M;
vector<pair<int,int> > House;
vector<pair<int,int> > Chicken;
vector<int> Pickedindex;
int ans = INF;

int distance(pair<int,int> a,pair<int,int> b)
{
	return abs(a.X-b.X) + abs(a.Y-b.Y);
}

int traverse()
{
	int Mindis = 0;//도시의 치킨거리
	int dis;
	for(int i = 0;i<House.size();i++)
	{
		dis = INF;//집당 치킨거리
		for(int j = 0;j<M;j++)
		{
			dis = min(dis,distance(House[i],Chicken[Pickedindex[j]]));
		}
		Mindis+=dis;
	}
	return Mindis;
}

void pick(int start, int index)//폐업시키지 않을 치킨집선택
{
	if(index == M)
	{
		ans = min(ans,traverse());
		return;
	}
	
	for(int i = start;i<Chicken.size();i++)
	{
		Pickedindex.push_back(i);
		pick(i+1,index+1);
		Pickedindex.pop_back();
		pick(i+1,index);
	}
}

int main() 
{
	cin >> N >> M;
	for(int i = 0;i<N;i++)
	{
		for(int j =0;j<N;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j] == 1)
				House.push_back({i,j});
			if(arr[i][j] == 2)
				Chicken.push_back({i,j});
		}
	}
	pick(0,0);
	
	cout<<ans;
	
	return 0;
}
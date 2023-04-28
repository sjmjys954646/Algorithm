#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

struct knight
{
	pair<int,int> cur;
	int m;
};

bool dp[302][302];
int l;
pair<int,int> start;
pair<int,int> des;
int moveX[8] = {1,2,2,1,-1,-2,-2,-1};
int moveY[8] = {-2,-1,1,2,2,1,-1,-2};

int bfs()
{
	queue<knight> q;
	q.push({{start.first,start.second},0});
	while(!q.empty())
	{
		int curX = q.front().cur.first;
		int curY = q.front().cur.second;
		int m = q.front().m;
		q.pop();
		
		if(curX == des.first && curY == des.second)
			return m;
		
		for(int i = 0;i<8;i++)
		{
			int nextX = curX + moveX[i];
			int nextY = curY + moveY[i];
			
			if(nextX < 0 || nextY < 0 || nextX >= l || nextY >= l)
				continue;
			
			if(dp[nextY][nextX] == true)
				continue;
			
			dp[nextY][nextX] = true;
			q.push({{nextX,nextY},m+1});
		}
	}
	return 0;
}

int main()
{
	int T;
	
	scanf("%d",&T);
	
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		int a, b;
		
		scanf("%d",&l);
		scanf("%d %d",&a,&b);
		start = {a,b};
		scanf("%d %d",&a,&b);
		des = {a,b};
		printf("%d\n",bfs());
	}

	return 0;
}
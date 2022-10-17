#include <iostream>
using namespace std;

struct Point
{ 
	int x,y,p,q;
}; 
	
int isIntersect(Point p1, Point p2)
{ 
	if(p1.x>p2.p || p2.x>p1.p) 
		return 0; 
	if(p1.y>p2.q || p2.y>p1.q)
		return 0;
	return 1;
} 

int isLine(Point p1, Point p2)
{ 
	if(p1.q == p2.y) 
		return 1;
	if(p1.p == p2.x) 
		return 1;
	return 0; 
} 

int isPoint(Point p1, Point p2)
{ 
	if(p1.p==p2.x && p1.q==p2.y) 
		return 1; 
	if(p1.p==p2.x && p1.y==p2.q)
		return 1; 
	return 0; 
} 

int main() 
{
	for(int i = 0;i<4;i++)
	{
		Point p1,p2;
		scanf("%d %d %d %d",&p1.x,&p1.y,&p1.p,&p1.q);
		scanf("%d %d %d %d",&p2.x,&p2.y,&p2.p,&p2.q);
		
		if(isIntersect(p1, p2) || isIntersect(p2,p1) )
		{
			if(isPoint(p1,p2) || isPoint(p2,p1))	
			{
				cout << "c";
			}
			else if(isLine(p1,p2) || isLine(p2,p1))
			{
				cout<<"b";
			}
			else
			{
				cout<<"a";
			}
		}
		else 
		{
			cout<<"d";
		}
		cout<<"\n";
	}

	return 0;
}
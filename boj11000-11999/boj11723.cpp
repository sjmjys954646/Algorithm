#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int num, set;

int convert(char a)
{
	return (int)a - 49;
}

int main() 
{
	int set = 0;
	cin >> num;
	char ord[10000];
	while(num--)
	{
		scanf(" %[^\n]",ord);
		string order(ord);
		if(order.substr(0,3) == "add")
		{
			set |= (1<<convert(order[4]));
		}
		else if(order.substr(0,3) == "rem")
		{
			set &= ~(1<<convert(order[7]));
		}
		else if(order.substr(0,3) == "che")
		{
			if((set & (1<<convert(order[6]))))
				cout<<1<<"\n";
			else
				cout<<0<<"\n";
		}
		else if(order.substr(0,3) == "tog")
		{
			set ^= (1<<convert(order[7]));
		}
		else if(order.substr(0,3) == "all")
		{
			set = (1<<20) - 1;	
		}
		else if(order.substr(0,3) == "emp")
		{
			set = 0;
		}
	}

	return 0;
}
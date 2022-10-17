#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::vector;
using std::string;

void Division(int array[][128], int N, int row, int column) 
{
	if(N==1)
	{
		if(array[row][column] == 1)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
		return;
	}
	else
	{
		int sum = 0;
		
		for(int i = row;i<row+N;i++)
		{
			for(int j = column;j<column+N;j++)
			{
				sum += array[i][j];
			}	
		}
		if(sum == N*N)
		{
			cout<<"1";
			return;
		}
		else if(sum == 0)
		{
			cout<<"0";
			return;
		}
		else
		{	
			cout<<"(";
			Division(array, N/2, row, column);
			Division(array, N/2, row , column+ N/2);
			Division(array, N/2, row+ N/2, column);
			Division(array, N/2, row + N/2, column + N/2);
			cout<<")";
		}
	}
}

int main(void)
{
	string temparr;
	int array[128][128];
	int N;
	int row = 0;
	int column = 0;
	int sum = 0;
	
	cin>>N;
	
	for(int i =0;i<N;i++)
	{
		cin>>temparr;
		for(int m =0;m<N;m++)
		{
			array[i][m] = temparr[m]-'0';
		}	
	}

	Division(array, N, row, column);
	
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

inline unsigned long int min(unsigned long int x, unsigned long int y) { return x > y ? y : x;} 

unsigned long int MatrixMul(int num, int * arr)
{
	unsigned long int Marr[num][num];
	unsigned long int tmp=-1;
	
	for(int l=0;l<num;l++)
	{
		Marr[l][l] = 0;
	}
	
	for(int i =0;i<num-1;i++)
	{
		int j =0;
		for(int m=i+1;m<num;m++,j++)
		{
			tmp = -1;
			for(int k =j;k<j+i+1;k++)
			{
				if(tmp == -1)
					tmp = Marr[j][k]+Marr[k+1][m]+arr[j]*arr[k+1]*arr[m+1];
				else
					tmp= min(tmp,Marr[j][k]+Marr[k+1][m]+arr[j]*arr[k+1]*arr[m+1]);
			}
			Marr[j][m] = tmp;
		}
	}
	
	return Marr[0][num-1];
}
	  
int main(void)
{
	int N;
	int arr[501];
	int tmp;
	
	cin>>N;
	for(int i =0;i<N;i++)
	{
		if(i==N-1)
			cin>>arr[i]>>arr[i+1];
		else
		 	cin>>arr[i]>>tmp;
	}
	
	cout<<MatrixMul(N,arr);
	
	return 0;
}
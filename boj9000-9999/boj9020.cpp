#include <iostream>

using namespace std;

int main()
{
	int T,k;
	int arr[12000];
	int num = 0;
	int split;
	
	for(int i =1;i<12000;i++)
		arr[i] = i;
	
	for(int i =2;i<12000;i++)
	{
		for(int k = 2;i*k<12000;k++)
		{	
			arr[i*k] = 0;
		}	
	}
	
	arr[1] = 0;
	
	cin>>T;
	
	for(int i =0;i<T;i++)
	{
		cin>>k;
		num = k/2;
		
		for(int j =num;j>0;j--)
		{
			if(arr[j]!=0)
			{
				split = arr[j];
				if(arr[k-split]!=0)
				{
					break;
				}
			}
		}
		
		cout<<split<<" "<<k-split<<"\n";
	}
	
	return 0;
}
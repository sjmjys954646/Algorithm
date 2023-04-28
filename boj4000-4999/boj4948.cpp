#include <iostream>

using namespace std;

int main()
{
	int T;
	int arr[300000];
	int num = 0;
	
	for(int i =1;i<300000;i++)
		arr[i] = i;
	
	for(int i =2;i<300000;i++)
	{
		for(int k = 2;i*k<300000;k++)
		{	
			arr[i*k] = 0;
		}	
	}
	
	arr[1] = 0;
	
	while(true)
	{
		cin>>T;
		if(T==0)
			break;
		
		for(int i=T+1;i<=2*T;i++)
		{
			if(arr[i]!=0)
				num+=1;
		}
		
		cout<<num<<"\n";
		num = 0;
	}

	return 0;
}
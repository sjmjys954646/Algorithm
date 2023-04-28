#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int A;
	int Ans=0;
	int Arr[42] = {0,};
	for(int i = 0;i<10;i++)
	{
		cin>>A;
		A%=42;
		Arr[A]++;
	}
	
	for(int i = 0;i<42;i++)
	{
		if(Arr[i]!=0)
		{
			Ans++;
		}
	}
	
	cout<<Ans;
	
	return 0;
}

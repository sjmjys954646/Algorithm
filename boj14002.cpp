#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <cstring>
using namespace std;

int main()
{
	int num;
	int arr[1002];
	int dp[1002];
  int before[1002];
	int Max = 0;

  memset(before,-1,sizeof(before));

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

  int p;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
        before[i] = j;
			}
		}
    if(Max < dp[i])
    {
      Max = dp[i];
      p = i;
    }
	}
	cout << Max<<"\n";
  
  int t = p;
  vector<int> ans;
  while(true)
  {
    ans.push_back(arr[t]);  
    if(before[t] == -1)
      break;
    t = before[t];   
  }
  reverse(ans.begin(),ans.end());
  for(int i = 0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }

	return 0;
}
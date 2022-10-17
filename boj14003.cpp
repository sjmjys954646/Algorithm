#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <cstring>
#include <stack>

using namespace std;

int arr[1000020];
int LIS[1000020];
pair<int, int> ans[1000020];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

	int num;
  stack<int> s;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

  int idx = 0;
  LIS[idx] = arr[0];
  ans[0] = {0,arr[0]};

  for(int i = 1;i<num;i++)
  {
    if(LIS[idx]<arr[i])
    {
      LIS[++idx] = arr[i];
      ans[i] = {idx,arr[i]};
    }
    else
    {
      int tmp = lower_bound(LIS, LIS + idx, arr[i]) - LIS;
      LIS[tmp] = arr[i];
      ans[i] = {tmp,arr[i]};
    }
  }
	cout << idx + 1 <<"\n";

  int p = idx;
  for(int i=num - 1;i>=0;i--)
  {
    if(ans[i].first==p)
    {
      s.push(ans[i].second);
      p--;
    }
  }

  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }

	return 0;
}

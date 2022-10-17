#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
using namespace std;

int N;
int arr[30001];
int ans = -1;
vector<int> ansvec;
int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

    for(int i = 1;i<=30000;i++)
    {
        vector<int> tmp;
        tmp.push_back(N);
        tmp.push_back(i);
        int a = N;
        int b = i;
        int t = a-b;
        
        while(t>=0)
        {
            tmp.push_back(t);
            a = b;
            b = t;
            t = a-b;
        }

        arr[i] = tmp.size();
        ans = max(ans,arr[i]);
    }
    
     for(int i = 1;i<=30000;i++)
    {
        if(arr[i] == ans)
        {
            vector<int> tmp;
            tmp.push_back(N);
            tmp.push_back(i);
            int a = N;
            int b = i;
            int t = a-b;
        
            while(t>=0)
            {
                tmp.push_back(t);
                a = b;
                b = t;
                t = a-b;
            }
            ansvec.assign(tmp.begin(),tmp.end());
        }
        
        
    }

    cout<<ans<<"\n"; 

    for (auto &item : ansvec)
    {
       cout << item << " ";
    }


    return 0;
}
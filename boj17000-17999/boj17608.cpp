#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<int> arr;

    cin >> N;

    for(int i = 0;i<N;i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    reverse(arr.begin(),arr.end());

    int ans = 0;
    int r = -1;

    for(int i = 0;i<arr.size();i++)
    {
        if(r < arr[i])
        {
            ans++;
            r = arr[i];
        }
    }

    cout<<ans;

    return 0;
}

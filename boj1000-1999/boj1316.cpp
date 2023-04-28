#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define X first
#define Y second
#define endl "\n"

using namespace std;

int N;
bool arr[28];
vector<string> vec;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        vec.push_back(a);
    }
    
    for (int i = 0; i < N; i++)
    {
        memset(arr, 0, sizeof(arr));
        bool succeed = true;
        arr[vec[i][0] - 'a'] = true;
        for (int j = 1; j < vec[i].length(); j++)
        {
            int t = vec[i][j]-'a';
            if (arr[t] == true && vec[i][j-1] != vec[i][j])
            {
                succeed = false;
                break;
            }
            else
            {
                arr[t] = true;
            }
        }

        if (succeed)
            ans++;
    }

    cout << ans;

    
}
#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int result;
    if(a == b && a == c)result = 10000 + a * 1000;
    else if((a == b || a == c) || b == c) 
    {
        if( a == b)result = 1000 + a * 100;
        if( c == b)result = 1000 + c * 100;
    }
    else result = max(max(a, b), c) * 100;

    cout << result;


}
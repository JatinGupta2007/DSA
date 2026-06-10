#include<iostream>
using namespace std;
int main()
{
    // a^b 
    int a = 10;
    int b = 10;
    int result = 1;

    while(b > 0){

        if(b & 1) {// odd
        result = result * a;
    }
    a = a * a;
    b = b >> 1;  //b/2;

    }
    int ans = result ;
    cout << ans;
    
return 0;
}
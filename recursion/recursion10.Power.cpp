// #include<iostream>
// using namespace std;

// int calPower(int a , int b , int product){
//     if(b == 0){
//         return product;
//     }
//     product = product * a;
//     b--;
//     return calPower(a,b,product);
// }
// int main()
// {
//     int a = 2;
//     int b = 10;
//     int ans = calPower(a , b , 1);
//     cout<< ans;
//     return 0;
// }


// Fast exponentation using recursion
#include<iostream>
using namespace std;

int power(int a , int b ){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }

    int ans = power(a , b/2);

    if (b%2 == 0){
        return ans*ans;   
    }
    else{
        return a*ans*ans;
    }
    
}
int main()
{
    int a = 3;
    int b = 11;
    int ans = power(a , b );
    cout<< ans;
    return 0;
}
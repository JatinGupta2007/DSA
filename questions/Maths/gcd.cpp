#include<iostream>
using namespace std;
int gcd(int a , int b){

    if(a  == 0){
        return b ;
     }
     else if(b == 0){
        return a;
     }

     while(a != b){
     if(a>b){
        a = a - b;
     }
     else if(b > a){
        b = b - a;
     }
    }
    return a;

}
int main()
{
    int a , b;
    cout<<"Enter value of a : ";
    cin>>a;
    cout<<"Enter value of b : ";
    cin>>b;

    cout<<"GCD of a and  b is "<<gcd(a,b)<<endl;
return 0;
}
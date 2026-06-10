#include<iostream>
using namespace std;

bool checkRotatedAndSorted(int arr[] , int n){

    int count = 0;

    for(int i = 0; i < n; i++){
        if(arr[i%n] > arr[(i+1)%n]){
            count++;
        }
    }

    if(count>1){
        return false;
    }
    return true;
}
int main()
{
    int arr[6] = {1,1,1,1,1,1}; 
    cout<<checkRotatedAndSorted(arr,6);

    
return 0;
}
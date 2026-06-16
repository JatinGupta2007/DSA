#include<iostream>
using namespace std;

int  arraySum(int array[] , int size , int sum){

    //BASE CASE
    if (size == 0){
        return sum;
    }

    //RR
     sum = sum + array[0];
    return arraySum(array + 1 , size - 1 , sum);

    
}
int main()
{
    int arr[8] = {1,2,3,4,5};
    int size = 5;
    int sum = 0;
    cout<<arraySum(arr , size , sum);;

return 0;
}



// int getSum(int *arr, int size) {

//     //base case
//     if(size == 0) {
//         return 0;
//     }
//     if(size == 1 )
//     {
//         return arr[0];
//     }

//     int remainingPart = getSum(arr+1, size-1);
//     int sum = arr[0] + remainingPart;
//     return sum;
// }
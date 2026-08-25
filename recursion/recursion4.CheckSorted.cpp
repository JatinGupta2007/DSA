#include<iostream>
using namespace std;

bool isSorted(int array[] , int size){

    //BASE CASE
    if(size == 0 || size == 1){
        return true;
    }

    //RR

    if(array[0] > array[1]){
        return false;
    }
    else{
        bool ans = isSorted (array+1 , size - 1);
        return ans;
    }
}
int main()
{
    int arr[8] = {1,2,3,4,5,6,8,7};
    int size = 8;

    int ans = isSorted (arr , size );
    if(ans == true){
        cout<<"Sorted";
    }
    else{
        cout<<"Unsorted";
    }

return 0;
}
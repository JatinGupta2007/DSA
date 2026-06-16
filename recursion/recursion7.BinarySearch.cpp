#include<iostream>
using namespace std;

bool search(int array[] , int size , int target , int start , int end){

    // BASE CASE
    if(start > end){
        return false;
    }
    

    // RECURSIVE
    int mid = start + (end - start)/2;

    if(array[mid] == target){
        return true;
    }
    else if(array[mid] > target){
        end = mid - 1;
    }
    else if(array[mid] < target){
        start = mid + 1;
    }

    return search(array , size , target , start , end);
}
int main()
{
    int arr[8] = {1,2,3,4,5,6,7,8};
    int size = 8 , target = 5 , start = 0 , end = size - 1;
    bool ans = search(arr , size , target , start , end);
    cout<<ans;
return 0;
}
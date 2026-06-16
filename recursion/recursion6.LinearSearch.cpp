#include<iostream>
using namespace std;

bool find(int array[] , int size, int target){

    //BASE CASE
    if(size == 0) {
        return false;
    }

    //RR

    if(array[0] == target){
        return true;
    }
    else{
    bool ans = find(array+1 , size - 1 , target);
    return ans;
    }
}
int main()
{
    int arr[8] = {1,2,3,4,4,6,8,5};
    int size = 8;
    int target = 5;
    cout<< find(arr , size , target);

return 0;
}
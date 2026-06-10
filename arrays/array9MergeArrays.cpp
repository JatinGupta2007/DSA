#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr1[] , int n, int arr2[] , int m , int arr3[]){
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < n || j < m){
        if(arr1[i]<arr2[j] && i<n){
            arr3[count] = arr1[i];
            i++;  
            count++;
        }
        else{
            arr3[count] = arr2[j];
            j++;
            count++;
        }
    }
}
int main()
{
    int arr[3] = {1,3,5};
    int brr[5] = {2,4,9,11,14};
    int crr[8];

    merge(arr,3,brr,5,crr);
    printArray(crr,8);
return 0;
}
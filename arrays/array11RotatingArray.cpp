// OPTIMISED 
// OPTIMISED 

// #include<iostream>
// using namespace std;

// void printArray(int arr[], int n) {
//     for(int i=0; i<n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void rotate(int arr[],int arr2[], int n,int k){

//     for(int i = 0; i < n; i++){
//         arr2[(i+k)%n] = arr[i];
//     }
    
// }
// int main()
// { 
//     int arr[5] = {1,2,3,4,5};
//     int brr[5];
//     rotate(arr,brr,5,2);
//     printArray(brr,5);

    
// return 0;
// }



// Brute force

#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotate(int array[] , int k , int n ){
    for(int i = 0 ; i < k; i++){
        int temp = array[n-1];
        for(int j = n - 1; j >= 0; j--){
            if(j==0){
                array[j] = temp;
                break;
            }
        
            array[j] = array[j-1];
            
        }
    }
}
int main()
{
    int arr[] = {1,2,3,4,5};
     rotate(arr,3,5);
     printArray(arr,5);
return 0;
}
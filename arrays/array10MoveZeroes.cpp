// #include<iostream>
// using namespace std;
// void printArray(int arr[], int n) {
//     for(int i=0; i<n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void moveZero(int arr[] , int n,int arr2[]){
//     int i = 0;
//     int nonZero = 0;
//     int zero = n-1;
//     while(i < n){
//     if(arr[i] != 0){
//         arr2[nonZero] = arr[i];
//         nonZero++;
//         i++;
//     }
//     else if(arr[i] == 0){
//         arr2[zero] = arr[i];
//         i++;
//         zero--;

//     }
// }
// }
// int main()
// {

//     int arr[5] = {0,1,0,3,12};
//     int brr[5];
//     moveZero(arr,5,brr);
//     printArray(brr,5);
    
// return 0;
// }




#include<iostream>
using namespace std;
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void moveZero(int arr[] , int n){
    int i = 0;
    int nonZero = 0;
    int zero = n-1;
    while(i < n){
    if(arr[i] != 0){
        swap(arr[i] , arr[nonZero]);
        nonZero++;
        i++;
    }
    else {
        i++;
    }
}
}
int main()
{

    int arr[5] = {0,1,0,3,12};

    moveZero(arr,5);
    printArray(arr,5);
    
return 0;
}
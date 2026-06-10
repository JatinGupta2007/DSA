#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void bubbleSorting(vector<int> arr , int n){

    for(int i = 0; i < n; i++){

        // bool swapped = false;

        for(int j = 0; j < n - 1 ; j++){         // for(int j = 0; j < n - (i + 1); j++){
            if(arr[j+1] < arr[j]){
                swap(arr[j] , arr[j+1]);

        //        swapped = true;
            }
        }
        // if(swapped == false){
        //     break;
        // }
    }
    printArray(arr,n);
}
int main()
{
    vector<int> array= {64,25,12,22,11};
    bubbleSorting(array , array.size());

    
return 0;
}
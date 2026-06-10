#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSorting(vector<int> arr , int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i - 1;
        for(j; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;

    } 
    printArray(arr,n);
}
int main()
{
    vector<int> array= {64,25,12,22,11};
    insertionSorting(array , array.size());

    
return 0;
}

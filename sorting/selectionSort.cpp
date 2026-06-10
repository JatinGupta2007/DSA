#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSorting(vector<int> &arr , int n){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }   
        }
        swap(arr[i] , arr[minIndex]);
        
    }
    printArray(arr , arr.size());
}
int main()
{
    vector<int> array= {64,25,12,22,11};
    selectionSorting(array , array.size());

    
return 0;
}
#include<iostream>
#include<vector>
using namespace std;


// OLD CODE , A LITTLE CONFUSING

// void printArray(int arr[], int n) {
//     for(int i=0; i<n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void sort(int array[] , int size , int a , int b , int count){


//     if(count == size - 1){
//         return;
//     }

//     if(b == size - count){
//         return sort(array, size, 0, 1, count + 1);
//     }
    
//     if(array[a] > array[b]){
//         swap(array[a] , array[b]);
//         a++;
//         b++;
//     }
//     else if(array[a] <= array[b]){
//         a++;
//         b++;
//     }

//     return  sort(array , size , a , b , count);
// }
// int main()
// {
//     int arr[8] = {1,2,3,5,4,8,7,6};
//     int size = 8;
//     sort(arr , size , 0 , 1 , 0);
//     printArray(arr , size);
// return 0;
// }



class Solution {
public:
    void bubblePass(vector<int>& arr, int i, int n) {
        // base case: reached end of this pass
        if (i >= n - 1){
             return;
        }

        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }

        // recurse to next index — replaces the inner for loop
        bubblePass(arr, i + 1, n);
    }

    void bubbleSort(vector<int>& arr, int n) {
        // base case: array of size 0 or 1 is already sorted
        if (n <= 1){ 
            return;
        }

        // do one full pass via recursion (no loop)
        bubblePass(arr, 0, n);

        // recurse on the remaining unsorted portion — replaces the outer loop
        bubbleSort(arr, n - 1);
    }
};



// half recursion , half bubble sort


class Solution {
public:
    void bubbleSort(vector<int>& arr, int n) {

        // base case: array of size 0 or 1 is already sorted
        if (n <= 1){
            return ;
        } 

        // one full pass: bubble the largest unsorted element to the end
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }

        // recurse on the remaining unsorted portion (size n-1, last element now fixed)
        bubbleSort(arr, n - 1);
    }
};
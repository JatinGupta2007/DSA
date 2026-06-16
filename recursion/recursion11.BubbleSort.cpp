#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int array[] , int size , int a , int b , int count){


    if(count == size - 1){
        return;
    }

    if(b == size - count){
    return sort(array, size, 0, 1, count + 1);
    }
    
    if(array[a] > array[b]){
        swap(array[a] , array[b]);
        a++;
        b++;
    }
    else if(array[a] <= array[b]){
        a++;
        b++;
    }

    return  sort(array , size , a , b , count);
}
int main()
{
    int arr[8] = {1,2,3,5,4,8,7,6};
    int size = 8;
    sort(arr , size , 0 , 1 , 0);
    printArray(arr , size);
return 0;
}



// half recursion , half bubble sort


// #include<vector>
// using namespace std;
// void bubbleSort(vector<int>& arr, int n)
// {   
//     for(int i = 1; i<n; i++) {
//         //for round 1 to n-1
//         bool swapped = false;
        
//         for(int j =0; j<n-i; j++) {
            
//             //process element till n-i th index
//             if(arr[j] > arr[j+1]) {
//                 swap(arr[j], arr[j+1]);
//                 swapped = true;
//             }
            
//         }
        
//         if(swapped == false) {
//             //already sorted
//             break;
//         }
           
//     }
// }
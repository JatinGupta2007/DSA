#include<iostream>
using namespace std;

int getSum(int *arr, int n) {

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    } 
    return sum;
}

int main() {

    int n;
    cin >> n;
    
    //variable size array
    int* arr = new int[n];

    //takign inputn in aray
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    cout << "answer is "<< ans << endl;

//case 1   memory will only store in stack and then released after the loop is ended , so no crash
    while(true) {
        int i = 5;
    }
    
//case 2  memeory will store in heap  and will completly fill the heap and crash the program
    while(true) {
        int* ptr = new int;
    }




    return 0;
}
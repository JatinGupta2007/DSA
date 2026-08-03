#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr , int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sum(vector<int> &arr1 , int n , vector<int> arr2 , int m){
    
    int i = 0;
    while(i < m){
        arr1[n-i-1] = arr1[n-i-1] + arr2[m-i-1];
        i++;
    }
}
int main()
{

    vector<int> arr = {1,2,3,6};
    vector<int> brr = {9,9};
    sum(arr , 4 , brr , 2);
    printArray(arr , 4); 
    return 0;
}
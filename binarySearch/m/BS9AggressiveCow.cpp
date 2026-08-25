#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// you are given an array 'arr' consisting of 'n' integers which denote the position of a stall.

// You are also given an integer 'k' which denotes the number of aggressive cows.

// You are given the task of assigning stalls to 'k' cows such that the minimum distance
//  between any two of them is the maximum possible.

// Print the maximum possible minimum distance.

// Example:
// Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

// Output: 2
// Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at 
// positions {1, 3}. Here distance between cows is 2.

bool isPossible(vector<int> &arr, int n, int k, int gap)
{

    int count = 1;
    int lastPos = arr[0];

    for(int i = 1; i < n; i++){
    
        if(arr[i] - lastPos < gap){
            // ignore
        }
        else{
            lastPos = arr[i];
            count++;

            if(count >= k){
                return true;
            }
        }
    }
        return false;
 }

int allocateStall(vector<int> &arr, int n, int k)
{
    int low = 1;
    int high = arr[n-1] - arr[0];
    int ans = 0;
    
    while (low <= high)
    {
        int mid =  low + (high - low) / 2;

        if (isPossible(arr, n, k, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans ;
}

int main()
{

    vector<int> array = {1,2,4,8,9};
    sort(array.begin() , array.end());


    cout << allocateStall(array, array.size(), 3);   // cows should be taken from user

    return 0;
}
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

bool isPossible(vector<int> arr, int n, int k, int mid)
{


    int sum = 0;
    int countCow = 1;

    for (int i = 0; i < n; i++)
    {
        if(sum + arr[mid] < n){ 
            countCow++;
            sum = sum + arr[mid];
        }
        else{
            if(countCow < k){
                return false;
            }
            break;
        }
        }
        return true;
 }

int allocateStall(vector<int> arr, int n, int k)
{
    int min = 0;
    int max = n-1;
    int ans = 0;
    
    int mid = (min + max) / 2;
    while (min <= max)
    {
        mid = (min + max) / 2;

        if (isPossible(arr, n, k, mid))
        {
            ans = mid;
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return ans ;
}

int main()
{
    vector<int> array = {1,2,4,8,9};
    sort(array.begin() , array.end());


    cout << allocateStall(array, array.size(), 3);

    return 0;
}
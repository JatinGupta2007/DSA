#include <iostream>
#include <vector>
using namespace std;

// Given an array/list of length ‘n’, where the array/list represents the boards and each element of the 
// given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards.
// Consider that each unit of a board takes 1 unit of time to paint.

// You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards 
// under a constraint that any painter will only paint the continuous sections of boards.

// Example :
// Input: arr = [2, 1, 5, 6, 2, 3], k = 2

// Output: 11


bool isPossible(vector<int> arr, int n, int k, int area)
{
    int sum = 0;
    int painterCount = 1;

    for (int i = 0; i < n; i++)
    {

        if (sum + arr[i] <= area)
        {
            sum = sum + arr[i];
        }
        else
        {
            painterCount++;
            sum = arr[i];
            if (painterCount > k || arr[i] > area)
            {
                return false;
            }
        }
    }
    return true;
}

int allocateArea(vector<int> arr, int n, int k)
{
    
    int sum = 0;
    int maxNum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] > maxNum){
            maxNum = arr[i];
        }
        sum = sum + arr[i];
    }

    int low = maxNum;
    int high = sum;
    int ans = 0;
    
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> array = {1,4,4};
    cout << allocateArea(array, array.size(), 3);

    return 0;
}
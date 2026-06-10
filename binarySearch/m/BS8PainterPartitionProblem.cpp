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


bool isPossible(vector<int> arr, int n, int k, int mid)
{
    int area = 0;
    int painterCount = 1;

    for (int i = 0; i < n; i++)
    {

        if (area + arr[i] <= mid)
        {
            area = area + arr[i];
        }
        else
        {
            painterCount++;
            area = arr[i];
            if (painterCount > k || arr[i] > mid)
            {
                return false;
            }
        }
    }
    return true;
}

int allocateArea(vector<int> arr, int n, int k)
{
    int min = 0;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int max = sum;
    int mid = (min + max) / 2;
    while (min <= max)
    {
        mid = (min + max) / 2;

        if (isPossible(arr, n, k, mid))
        {
            ans = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> array = {2, 1, 5, 6, 2, 3};
    cout << allocateArea(array, array.size(), 2);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// BRUTE FORCE APPROACH

void rotate1(int array[], int k, int n)
{
    for (int i = 0; i < k; i++)
    {
        int temp = array[n - 1];
        for (int j = n - 1; j >= 0; j--)
        {
            if (j == 0)
            {
                array[j] = temp;
                break;
            }

            array[j] = array[j - 1];
        }
    }
}

// OPTIMISED APPROACH TAKING EXTRA SPACE

void rotate2(int arr[], int arr2[], int n, int k)
{

    for (int i = 0; i < n; i++)
    {
        arr2[(i + k) % n] = arr[i];
    }
}

// VERY OPTIMISED , THIS QUESTION TRICK APPROACH
void rotate3(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    // Step 1: reverse entire array
    reverse(nums.begin(), nums.end());

    // Step 2: reverse first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Step 3: reverse remaining n-k elements
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int brr[5];
    rotate2(arr, brr, 5, 2);
    printArray(brr, 5);

    return 0;
}

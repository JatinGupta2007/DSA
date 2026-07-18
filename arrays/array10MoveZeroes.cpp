#include <iostream>
#include <vector>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    // Using 2 pointers to do it(Making a new array)
    void moveZero1(int arr[], int n, int arr2[])
    {
        int i = 0;
        int nonZero = 0;
        int zero = n - 1;
        while (i < n)
        {
            if (arr[i] != 0)
            {
                arr2[nonZero] = arr[i];
                nonZero++;
                i++;
            }
            else if (arr[i] == 0)
            {
                arr2[zero] = arr[i];
                i++;
                zero--;
            }
        }
    }

    // Most optimal in place (one pass solution)
    void moveZero2(int arr[], int n)
    {
        int i = 0;
        int nonZero = 0;
        int zero = n - 1;
        while (i < n)
        {
            if (arr[i] != 0)
            {
                swap(arr[i], arr[nonZero]);
                nonZero++;
                i++;
            }
            else
            {
                i++;
            }
        }
    }

    // 2 pointer optimal in place approach (one pass solution)
    void moveZeroes3(vector<int> &nums)
    {
        int i = 0;
        int j = 1;

        while (j < nums.size())
        {
            if (nums[i] != 0)
            {
                i++;
                j++;
            }
            else if (nums[i] == 0 && nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
    }
};

int main()
{

    int arr[5] = {0, 1, 0, 3, 12};
    Solution* s = new Solution;
    s->moveZero2(arr, 5);
    printArray(arr, 5);

    return 0;
}
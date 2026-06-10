#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end)
        {
            int mid = start + ((end - start) / 2);

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid] > arr[mid - 1])
            {
                start = mid;
            }
            else if (arr[mid] < arr[mid - 1])
            {
                end = mid;
            }
        }
        return start;
    }
};
int main()
{
    vector<int> v1 = {1, 3, 8, 12, 15, 3, 2};
    Solution s1;
    cout << s1.peakIndexInMountainArray(v1);
}
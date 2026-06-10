#include <iostream>
using namespace std;
int pivot(int arr[], int size)
{
    int low = 0;
    int high = size - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= arr[0])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    // FINDING PIVOT IN ROTATED SORTED ARRAY
    int array[] = {7, 9, 1, 3, 5};
    cout << "The index of pivot array is " << pivot(array, 5);

    return 0;
}
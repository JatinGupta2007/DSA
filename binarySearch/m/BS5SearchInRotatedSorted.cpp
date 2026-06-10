#include <iostream>
using namespace std;
int getPivot(int arr[], int size)
{
    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;
    while (low < high)
    {
        mid = (low + high) / 2;

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

int binarySearch(int arr[], int min, int max, int search)
{
    while (min <= max)
    {
        int mid = (max + min) / 2; // mid = min + ((max - min)/2);
        if (arr[mid] < search)
        {
            min = mid + 1;
        }
        else if (arr[mid] > search)
        {
            max = mid - 1;
        }
        else if (arr[mid] == search)
        {
            return mid;
        }
    }
    return -1;
}

int search(int arr[], int target, int size)
{
    int pivot = getPivot(arr, size);
    if (target >= arr[pivot] && target <= arr[size - 1])
    {
        return binarySearch(arr, pivot, size - 1, target);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, target);
    }
}

int main()
{

    int array[] = {7, 9, 1, 3, 5, 6};
    cout << search(array, 5, 6);

    return 0;
}

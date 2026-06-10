#include <iostream>
using namespace std;

int firstOccurence(int arr[], int size, int search)
{
    int min = 0;
    int max = size - 1;
    int left = 0;
    while (min <= max)
    {
        int mid = (max + min) / 2;
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
            left = mid;
            max = mid - 1;
        }
    }
    if (left != 0)
    {
        return left;
    }
    else
    {
        return -1;
    }
}

int lastOccurence(int arr[], int size, int search)
{
    int min = 0;
    int max = size - 1;
    int right = 0;
    while (min <= max)
    {
        int mid = (max + min) / 2;
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
            right = mid;
            min = mid + 1;
        }
    }

    if (right != 0)
    {
        return right;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int even[10] = {1, 4, 7, 13, 13, 26, 27, 44, 44, 44};
    int odd[9] = {1, 2, 3, 5, 5, 5, 5, 8, 9};

    cout << firstOccurence(even, 10, 44) << endl
         << lastOccurence(even, 10, 44) << endl;
    cout << firstOccurence(odd, 9, 5) << endl
         << lastOccurence(odd, 9, 5) << endl;

    return 0;
}

// CAN FIND NUMBER OF OCCURENCES BY {(RIGHT - LEFT) + 1}

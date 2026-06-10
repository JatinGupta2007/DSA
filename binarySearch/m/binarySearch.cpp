#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int search)
{
    int min = 0;
    int max = size - 1;
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
int main()
{
    int even[10] = {1, 4, 7, 13, 15, 26, 27, 41, 44, 50};
    int odd[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << binarySearch(even, 10, 41) << endl;
    cout << binarySearch(odd, 9, 0) << endl;

    return 0;
}

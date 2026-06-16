#include <iostream>
using namespace std;


int partition(int *arr, int s, int e)
{

    int pivot = arr[s];
    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivot)
        {
            count++;
        }
    }
    int pivotIndex = s + count;

    // swap(arr[s] , arr[s + count]);
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        if (arr[i] > pivot && arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if (arr[i] < pivot)
        {
            i++;
        }
        else if (arr[j] > pivot)
        {
            j--;
        }
    }
    
    return pivotIndex;
}



void quickSort(int *arr, int s, int e)
{
    // Base case
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    // Sort left part
    quickSort(arr, s, p - 1);
    
    // Sort right part
    quickSort(arr, p + 1, e);
}



void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[6] = {3, 5, 1, 4, 6, 2};
    int size = 6;
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}
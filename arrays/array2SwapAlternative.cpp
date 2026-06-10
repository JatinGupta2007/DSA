#include <iostream>
using namespace std;
void swapAlternative(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if ((i + 1) % 2 == 1 && (i + 1) != size)
        {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }
    return;
}
int main()
{
    int arr[20] = {1, 5, 7, 9, 12, 7};
    int size = 6;

    swapAlternative(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
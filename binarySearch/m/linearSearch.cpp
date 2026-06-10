#include <iostream>
using namespace std;
void linearSearch(int array[], int num, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (num == array[i])
        {
            cout << "Yes the number is present in the array at index " << i << endl;
            return;
        }
    }
    cout << "No the number is not present in the array" << endl;
}
int main()
{
    int arr[50] = {2, 67, 43, 5, 44, 35, -65, 354, 32, 1, 5};
    int size = 11;

    // cout<<"Enter the number of elements in the array: "<<endl;
    // cin>>size;

    // cout<<"Enter the values"<<endl;

    // for(int i = 0; i < size; i++){
    //     cin>>arr[i];
    // }

    int num;
    cout << "Enter the number you want to find :";
    cin >> num;
    linearSearch(arr, num, size);

    return 0;
}
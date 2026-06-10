#include <iostream>
using namespace std;

// int findUnique(int array[], int size)
// {

//     int num = 0;
//     for (int j = 0; j < size + 1; j++)
//     {

//         if (num == array[j - 1] && j != 0)
//         {
//             return num;
//         }

//         // if(num != 0 && j != 0){
//         //     return num;
//         // }

//         num = array[j];
//         for (int i = 0; i < size; i++)
//         {
//             if (num == array[i] && i != j)
//             {
//                 num = 0;
//                 break;
//             }
//         }
//     }
//     return 0;
// }
// int main()
// {
//     int arr[11] = {2, 2, 9, 9, 1};
//     int size = 5;
//     int unique = findUnique(arr, size);
//     if (unique == 0)
//     {
//         cout << "There is no unique element in the array" << endl;
//         return 0;
//     }
//     cout << "The unique element in the array is " << unique;

//     return 0;
// }



// OPTIMISED SOLUTION (O(N))
int main()
{
    int arr[11] = {9, 1, 1, 2, 2};
    int size = 5;
    int Ans = 0;
    for (int i = 0; i < size; i++)
    {
        Ans = Ans ^ arr[i];
    }
    cout << Ans;
    return 0;
}
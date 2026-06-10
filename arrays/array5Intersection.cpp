// #include <iostream>
// using namespace std;
// int main()
// {
//     // Both the arrays are in increasing order
//     int arr[] = {1, 2, 3, 4, 5};
//     int brr[] = {3, 4};
//     int crr[5];
//     int size = sizeof(arr) / 4;
//     int size2 = sizeof(brr) / 4;

//     int count = 0;

//     for (int i = 0; i < size; i++)
//     {
//         int num = arr[i];
//         for (int j = 0; j < size2; j++)
//         {

//             // OPTIMISATION
//             // if (num < brr[j])
//             // {
//             //     break;
//             // }

//             if (num == brr[j])
//             {
//                 crr[count] = num;
//                 brr[j] = INT_MIN;
//                 count++;
//                 break;
//             }
//         }
//     }

//     for (int i = 0; i < count; i++)
//     {
//         cout << crr[i] << endl;
//     }

//     return 0;
// }

#include <iostream>
#include<vector>
using namespace std;
int main()
{
    // Both the arrays are in increasing order
    vector<int>arr = {1, 3, 5, 7 , 13};
    vector<int>brr = {2, 4 , 5 , 7 ,11};
    vector<int>ans;

    int i = 0;
    int j = 0;
    while( i != arr.size() && j != brr.size()){

        if(brr[j] > arr[i]){
            i++;
        }
        else if(brr[j] == arr[i]){
            ans.push_back(arr[i]);
            cout<<arr[i]<<endl;
            brr[j] = INT_MIN;
            i++;
            j++;
        }
        else if(brr[j] < arr[i]){
            j++;
        }
    }
    return 0;

}

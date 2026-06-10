#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4

    // for(int i = 1;  i<= n; i++){
    //     int j;
    //     for( j = 1; j <= n; j++ ){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // 3 2 1
    // 3 2 1
    // 3 2 1

    // for(int i = 1; i<=n; i++){
    //     for(int j = n ; j > 0 ; j--){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // 1 2 3
    // 4 5 6
    // 7 8 9

    // for(int i = 1; i <= n ; i++){

    //     for(int j = 1 ; j <= n ; j++){
    //         static int k = 1 ;
    //         cout<<k<<" ";
    //         k++;
    //     }
    //     cout<<endl;
    // }

    // 1
    // 2 3
    // 3 4 5
    // 4 5 6 7

    // for(int i = 1; i <= n; i++){
    //     int count = i;
    //     for(int j = 1; j <= i; j++){
    //         cout<<count<<" ";
    //         count++;
    //     }
    //     cout<<endl;
    // }

    // A B C
    // A B C
    // A B C

    // for (int  i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++){
    //         char ch = 'A' + j - 1;
    //         cout<<ch<<" ";
    //     }
    //     cout<<endl;

    // }

    // A B C
    // B C D
    // C D E

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         char ch = 'A' + i + j - 2;
    //         cout<<ch<<" ";

    //     }
    //     cout<<endl;
    // }

    // A
    // B C
    // C D E

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= i; j++){
    //         char ch = 'A' + i + j - 2;
    //         cout<<ch<<" ";

    //     }
    //     cout<<endl;
    // }

    // D
    // C D
    // B C D
    // A B C D

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= i; j++){
    //         char ch = 'A' + n - 1 - i + j;
    //         cout<<ch<<" ";

    //     }
    //     cout<<endl;
    // }

    //    *
    //   **
    //  ***
    // ****

    //  for(int i = 1 ; i <= n; i++){
    //     for(int j = n; j > 0; j--){
    //         if(j <= i){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    //    1
    //   121
    //  12321
    // 1234321

    // for(int i = 1; i <= n; i++){
    //     int count = i;
    //     for(int j = 1; j <= n + i - 1; j++){

    //         if(j < n - i + 1){
    //             cout<<" ";
    //         }

    //         else if(j > n){

    //             cout<< count - 1  ;
    //             count--;
    //         }
    //         else{
    //             cout<< i + j - n;
    //         }

    //     }
    //     cout<<endl;
    // }

    //    1
    //   121
    //  12321
    // 1234321

    for (int i = 1; i <= n; i++)
    {
        int count = i;
        for (int j = 1; j <= n + i - 1; j++)
        {
            if (j == n)
            {
                cout << count;
            }
            else if (j > n && j <= n + i - 1)
            {
                cout << count - j + n;
            }
            else if (j < n && j >= n - i + 1)
            {
                cout << count + j - n;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

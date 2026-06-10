#include<iostream>
using namespace std;
int main()
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    int row = 3 , column = 3;

    for(int j = 0; j < column; j++){
        for(int i = 0; i < row; i++){
            if((j%2) == 0){
                cout<<arr[i][j]<<" ";
            }
            else{
                cout<<arr[row-1-i][column-1-j]<<" ";
            }
        }
     }



// for(int j = 0; j < column; j++){

//     if(j%2 == 1){

//         for(int i = row - 1 ; i >= 0; i--){
//             cout<<arr[i][j]<<" ";
//         }
    
//     }
//     else{
//         for(int i = 0; i < row; i++){
//             cout<<arr[i][j]<<" ";
//         }
        
//     }
// }

return 0;
}




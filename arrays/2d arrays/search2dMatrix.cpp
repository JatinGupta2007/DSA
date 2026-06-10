// DOING BINARY SEARCH ON A 2D ARRAY BY CONSIDERING IT AS A OPENED 1 D ARRAY

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int s = 0;
        int e = (row*col) - 1;
        int mid = s + (e/2 - s/2);

        while(s<=e){
            mid = s + (e/2 - s/2);
            int element = matrix[mid/col][mid%col];
       
 
            if( element > target){
                e =  mid - 1;
            }

            else if (element < target){
                s = mid + 1;
            }
            else if( element == target){
                return true;
            }
        }
        return false;
        
    }
    };


    // FIND THE ROW WHERE SOLN IS PRESENT AND THEN DOING LINEAR SEARCH IN THAT ROW

//     class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//          int row = matrix.size();
//         int col = matrix[0].size();

//             int ansRow = INT_MIN;
//             int i = 0;

//             while(i < row){
//             if(matrix[i][col-1] > target){
//                 ansRow = i;
//                 break;
//             }
//             else if(matrix[i][col-1] < target){
//                 i++;
//             }
//             else if(matrix[i][col-1] == target){
//                 return true;
//             }
//         }

//         if(ansRow != INT_MIN){

//         for(int j = 0; j < col; j++){
//             if(matrix[ansRow][j] == target){
//                 return true;
//             }
//         }
//         }
//         return false;
        
//     }
// };

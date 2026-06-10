class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        // start from top right corner
        int i = 0, j = col - 1;

        while(i < row && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                j--;  // go left
            }
            else{
                i++;  // go down
            }
        }
        return false;
    }
};
#include<iostream>
#include<vector>
using namespace std;


// class Solution
// {
//     void solve(vector<vector<int>> &maze, vector<string> &ans,int n, vector<vector<int>> &compare, int row, int col, string &path)
//     {

//         // Base Case
//         if (row == n-1 && col == n-1)
//         {
//             ans.push_back(path);
//             return;
//         }

//         // Down
//         if (row != n - 1 && maze[row + 1][col] == 1 && compare[row + 1][col] == 0)
//         {
//             path.push_back('D');
//             compare[row + 1][col] = 1;
//             solve(maze, ans, n, compare, row + 1, col, path);
//             compare[row + 1][col] = 0;
//             path.pop_back();
//         }
//         // Up
//         if (row != 0 && maze[row - 1][col] == 1 && compare[row - 1][col] == 0)
//         {
//             path.push_back('U');
//             compare[row - 1][col] = 1;
//             solve(maze, ans, n, compare, row - 1, col, path);
//             compare[row - 1][col] = 0;
//             path.pop_back();
//         }

//         // Right
//         if (col != maze[0].size() - 1 && maze[row][col + 1] == 1 && compare[row][col + 1] == 0)
//         {
//             path.push_back('R');
//             compare[row][col + 1] = 1;
//             solve(maze, ans, n, compare, row, col + 1, path);
//             compare[row][col + 1] = 0;
//             path.pop_back();
//         }

//         // Left

//         if (col != 0 && maze[row][col - 1] == 1 && compare[row][col - 1] == 0)
//         {
//             path.push_back('L');
//             compare[row][col - 1] = 1;
//             solve(maze, ans, n, compare, row, col - 1, path);
//             compare[row][col - 1] = 0;
//             path.pop_back();
//         }

//         return;
//     }

// public:
//     vector<string> ratInMaze(vector<vector<int>> &maze, int n)
//     { // maze is n*n square matrix

//         vector<string> ans;

//         if (maze[0][0] == 0)
//         {
//             return ans;
//         }

//         int row = 0, col = 0;

//         // Making a compare matrix having all elements 0

//         vector<vector< int >> compare = maze;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 compare[i][j] = 0;
//             }
//         }
//         compare[0][0] = 1;

//         string path;
//         solve(maze, ans,n, compare, row, col, path);
//         return ans;
//     }
// };









// recent try

class Solution{
    public:

    void solve(vector<vector<int>> &grid , int m , int n , int x , int y , vector<string> &output , 
               string &ans , vector<vector<bool>> &check){
        
        // base case
        if(m == x-1 && n == y-1 && grid[m][n] == 1){
            output.push_back(ans);
            return ;
        }

          // down
        if(m < x-1 && grid[m+1][n] == 1 && check[m+1][n] == false ){
            check[m+1][n] = true;
            ans.push_back('D');
            solve(grid , m+1 , n , x , y , output , ans , check);
            check[m+1][n] = false;
            ans.pop_back();
        }

          // up
        if(m > 0 && grid[m-1][n] == 1 && check[m-1][n] == false ){
            check[m-1][n] = true;
            ans.push_back('U');
            solve(grid , m-1 , n , x , y , output , ans , check);
            check[m-1][n] = false;
            ans.pop_back();
        }

        // right
        if(n < y-1 && grid[m][n+1] == 1 && check[m][n+1] == false){
            check[m][n+1] = true ;
            ans.push_back('R');
            solve(grid , m , n+1 , x , y , output , ans , check);
            check[m][n+1] = false;
            ans.pop_back();
        }

        // left
        if(n > 0 && grid[m][n-1] == 1 && check[m][n-1] == false){
            check[m][n-1] = true;
            ans.push_back('L');
            solve(grid , m , n-1 , x , y , output , ans , check);
            check[m][n-1] = false;
            ans.pop_back();
        }
        return;
    }
        
    vector<string> findPath(vector<vector<int> > &grid) {

        int x = grid.size();
        int y = grid[0].size();

        vector<string> output;
        string ans;
        vector<vector<bool>> check(x , vector<bool>(y , false));

        int m = 0;
        int n = 0;

        if(grid[0][0] == 1){  
            check[0][0] = true;  
            solve(grid , m , n , x , y , output , ans , check);
        }
        return output;
    }
};
class Solution
{


    void solve(vector<vector<int>> &maze, vector<string> &ans,int n, vector<vector<int>> &compare, int row, int col, string &path)
    {

        // Base Case
        if (row == n-1 && col == n-1)
        {
            ans.push_back(path);
            return;
        }

        // Down
        if (row != n - 1 && maze[row + 1][col] == 1 && compare[row + 1][col] == 0)
        {
            path.push_back('D');
            compare[row + 1][col] = 1;
            solve(maze, ans, n, compare, row + 1, col, path);
            compare[row + 1][col] = 0;
            path.pop_back();
        }
        // Up
        if (row != 0 && maze[row - 1][col] == 1 && compare[row - 1][col] == 0)
        {
            path.push_back('U');
            compare[row - 1][col] = 1;
            solve(maze, ans, n, compare, row - 1, col, path);
            compare[row - 1][col] = 0;
            path.pop_back();
        }

        // Right
        if (col != maze[0].size() - 1 && maze[row][col + 1] == 1 && compare[row][col + 1] == 0)
        {
            path.push_back('R');
            compare[row][col + 1] = 1;
            solve(maze, ans, n, compare, row, col + 1, path);
            compare[row][col + 1] = 0;
            path.pop_back();
        }

        // Left

        if (col != 0 && maze[row][col - 1] == 1 && compare[row][col - 1] == 0)
        {
            path.push_back('L');
            compare[row][col - 1] = 1;
            solve(maze, ans, n, compare, row, col - 1, path);
            compare[row][col - 1] = 0;
            path.pop_back();
        }

        return;
    }

public:
    vector<string> ratInMaze(vector<vector<int>> &maze, int n)
    { // maze is n*n square matrix

        vector<string> ans;

        if (maze[0][0] == 0)
        {
            return ans;
        }

        int row = 0, col = 0;

        // Making a compare matrix having all elements 0
        vector < vector < int >> compare = maze;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                compare[i][j] = 0;
            }
        }
        compare[0][0] = 1;

        string path;
        solve(maze, ans,n, compare, row, col, path);
        return ans;
    }
};
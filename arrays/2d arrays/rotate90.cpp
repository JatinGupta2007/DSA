#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1 - Transpose (swap across diagonal)
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2 - Reverse each row
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// 90° Clockwise   → Transpose + Reverse each row
// 90° Anticlockwise → Transpose + Reverse each column
// 180°            → Reverse each row + Reverse each column
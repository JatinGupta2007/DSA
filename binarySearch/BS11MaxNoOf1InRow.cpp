#include <iostream>
#include <vector>
using namespace std;


// ALL ROWS ARE SORTED
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxRow = -1;
        int maxAns = -1;

        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = m - 1;
            int ans = 0;

            if(mat[i][0] == 1){
                return {i , m};
            }

            if(mat[i][m-1] == 0){
                continue;
            }


            while (start <= end) {
                int mid = end + (start - end) / 2;

                if(mat[i][mid] == 1){
                    ans = m - mid;
                    end = mid - 1;
                }

                else {
                    start = mid + 1;
                }
            }

            if(ans > maxAns){
                maxAns = ans;
                maxRow = i;
            }

        }

        return {maxRow, maxAns};
    }
};

// LEETCODE 2643 IS SIMILAR JUST ROWS ARE NOT SORTED IN IT
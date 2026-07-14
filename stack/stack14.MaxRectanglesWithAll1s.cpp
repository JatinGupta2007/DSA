#include<stack>
#include<vector>
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> heights) {
        int n = heights.size();
        int max = 0;
        stack<int> s;

        for(int i = 0; i < n; i++){

            while(!s.empty() && heights[s.top()] > heights[i]){
                int element = s.top();
                s.pop();

                int nse = i;
                int pse = s.empty() ? -1 : s.top();

                int area = heights[element] * (nse - pse - 1);

                if(area > max){
                    max = area;
                }
            }
            s.push(i);
        }

        while(!s.empty()){
            int element = s.top();
            s.pop();
            int nse = n;
            int pse = s.empty() ? -1 : s.top();

            int area = heights[element] * (nse - pse - 1);

            if(area > max){
                 max = area;
            }
        }
        return max;
    }
    
    int maxArea(vector<vector<int>> &mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        int max = 0;
        vector<int> sum;
        
        for(int i = 0; i < n; i++){
            
            for(int j = 0;j < m; j++){
                
                if(i == 0){
                    sum.push_back(mat[i][j]);
                    continue;
                }
                if(mat[i][j] == 0){
                    sum[j] = 0;
                }
                sum[j] = sum[j] + mat[i][j];
            }
            
            
            int area = largestRectangleArea(sum);
            if(area > max){
                max = area;
            }
            
        }
        return max;
    }
};
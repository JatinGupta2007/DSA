#include <iostream>
#include <vector>
using namespace std;


// Peak element is the element who is greater than above , below , right and left element

// We do binary search on number of columns  and then check the largest element of that column and then check if that element 
// is a peak element or not , if not then , if it is smaller than left side , end = mid  - 1 , if  smaller than right side
// start = mid + 1
class Solution {
public:

    int maxElement(vector<vector<int>>& mat , int n , int col){
        int maxNum = INT_MIN;
        int index = -1;
        for(int i = 0; i < n; i++){
            
            if(mat[i][col] > maxNum){
                maxNum = mat[i][col];
                index = i;
            }  
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int start = 0;
        int end = m - 1;

        while(start <= end){
            int mid = end + (start - end)/2;
            int maxRow = maxElement(mat , n , mid);

            int left = (mid == 0) ? -1 : mat[maxRow][mid-1];
            int right = (mid == m-1) ? -1 : mat[maxRow][mid+1];

            int val = mat[maxRow][mid];

            if(val > left && val > right){
                return {maxRow , mid};
            }
            else if(val < left){
                end = mid - 1;
            }
            else if(val < right){
                start = mid + 1;
            }
        }
        return {};     
    }
};
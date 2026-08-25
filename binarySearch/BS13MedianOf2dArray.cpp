#include <iostream>
#include <vector>
using namespace std;

// ALL ROW ARE SORTED 

// To find the median , we took a range (start = smallest element and end = largest element) and then did binary search on
// this answer space , we check the mid number , and find the count of numbers lesser than this mid number , if it greater than 
// median number it can be a ans , but check on left too , and if it is less than median number it cannot be our answer so check
// on right

// for finding the number of elements smaller than mid element in the 2d matrix , we transversed all the rows , and applied binary
// search on each row , and find the count of numbers lesser than our mid num , and return the count of total num lesser than
// mid num across all the 2d matrix.
class Solution{

    int findSmall(vector<vector<int>>&matrix, int n , int m , int num){

        int finalAns = 0;
        for(int i = 0; i < n; i++){
            int start = 0;
            int end = m-1;
            int ans = -1;

            while(start <= end){
                int mid = start + (end - start)/2;

                int element = matrix[i][mid];

                if(element > num){
                    end = mid -1;
                }
                else{
                    ans = mid;
                    start = mid + 1;
                }
            }
            finalAns += ans + 1;
        }
        return finalAns;
    }
public:
    int findMedian(vector<vector<int>>&matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int start = matrix[0][0];
        int end = matrix[n-1][m-1];

        int middleIndex = (n*m)/2;
        int finalAns = -1;

        while(start <= end){
            int mid = start + (end - start)/2;

            int smallerElements = findSmall(matrix , n, m , mid);

            if(smallerElements <= middleIndex){
                start = mid + 1;
            }
            else{
                finalAns = mid;
                end = mid-1;
            }
        }
        return finalAns;
    }
};
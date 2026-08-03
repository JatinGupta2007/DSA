#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

// Optimised sliding window approach
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0 ; i < k; i++){
            sum = sum + nums[i];
        }
        double maxAvg = sum/k;
        int i = 0;

        while(i+k < nums.size()){
            sum = sum - nums[i] + nums[i+k];

            if(sum/k > maxAvg){
                maxAvg = sum/k;
            }
            i++;
        }
        return maxAvg;
            
    }
};
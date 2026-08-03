#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:

// Kadane algo by me , easy to understand
    int maxSubArray(vector<int> &nums)
    {

        int maxSum = INT_MIN;
        int sum = 0;
        int i = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            
            if(sum < nums[i]){
                sum = nums[i];
            }

            if(sum > maxSum){
                maxSum = sum;
            }
            
        }
        return maxSum;
    }

    // Real kadane algo
    int maxSubArray2(vector<int> &nums)
    {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
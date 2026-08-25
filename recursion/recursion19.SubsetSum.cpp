#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    void solve(vector<int> &nums, vector<int> &ans ,int i , int sum) {
        
        // base case
        if(i >= nums.size()){
            ans.push_back(sum);
            return ;
        }


            // include
        sum = sum + nums[i];
        solve(nums , ans , i+1 , sum);

        // backtrack
        sum = sum - nums[i];
        solve(nums , ans , i+1 , sum);     
    }
    
public:
    vector<int> subsetSum(vector<int>& nums) {
        
        vector<int> ans;
        int i = 0;
        int sum = 0;
        solve(nums , ans , i , sum );

        sort(ans.begin(), ans.end());
        return ans;
    }
};
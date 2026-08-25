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

        for(int j = i; j < nums.size(); j++){


            if(j > i && nums[j] == nums[j-1]){
                continue;
            }

            // include
            sum = sum + nums[j];
            solve(nums , ans , j+1 , sum);

            // backtrack
            sum = sum - nums[j];  
    }
}
    
public:
    vector<int> subsetSum(vector<int>& nums) {


        sort(nums.begin() , nums.end());
        vector<int> ans;
        int i = 0;
        int sum = 0;
        solve(nums , ans , i , sum );

        sort(ans.begin(), ans.end());
        return ans;
    }
};
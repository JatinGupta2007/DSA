#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ** FOR LOOP WALA METHOD (EXTRA SPACE)
class Solution {
    private:
    void solve(vector<int> &nums, vector<bool> &check , vector<vector<int>> &output , vector<int> &ans
             , int index , int n){
        if(index >= n){
            output.push_back(ans);
            return;
        }

        for(int i = 0; i < n; i++){

            if(check[i] == true){
                continue;
            }

            ans.push_back(nums[i]);
            check[i] = true;
            solve(nums , check , output , ans , index+1 , n);
            ans.pop_back();
            check[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> output;
        vector<int> ans;
        vector <bool> check(n);
        int index = 0;
        solve(nums , check , output , ans , index , n);
        return output;
        
    }
};



// OPTIMISED SOLUTION

class Solution2 {
    private:
    void solve(vector<int> &nums, vector<vector<int>> &output , int index , int n){

        if(index >= n){
            output.push_back(nums);
            return;
        }

        for(int i = index; i < n; i++){
            swap(nums[index] , nums[i]);
            solve(nums , output , index+1 , n);
            swap(nums[index] , nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> output;
        int index = 0;
        solve(nums , output , index , n);
        return output;
        
    }
};
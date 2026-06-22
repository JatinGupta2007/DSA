class Solution
{
private:
    void solve(vector<int> nums, int index, vector<vector<int>> &ans)
    {
        // Base case
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= index)
            {
                swap(nums[index], nums[i]);
                solve(nums, index + 1, ans);

                // Back tracking
                swap(nums[index], nums[i]);
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, index, ans);
        return ans;
    }
};
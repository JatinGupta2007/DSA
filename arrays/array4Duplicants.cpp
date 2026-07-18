#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// Array contain elements from 1 to n-1 having one duplicant and is sorted and duplicate is last element

int findDuplicate(vector<int> &arr)
{
    int ans = 0;

    // XOR ing all array elements
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    // XOR [1, n-1]
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 4};
    cout << findDuplicate(arr);

    return 0;
}

// leetcode 442

// class Solution
// {
// public:
//     vector<int> findDuplicates(vector<int> &nums)
//     {
//       sort(nums.begin(), nums.end());
//         vector<int> ans;
//         for (int i = 1; i < nums.size(); i++)
//         {
//             if (nums[i] == nums[i - 1] && (i < 2 || nums[i] != nums[i - 2]))
//             {
//                 ans.push_back(nums[i]);
//             }
//         }
//         return ans;
//     }
// };


// Optimised hash map approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
            unordered_map<int, int> freq;
            freq.reserve(nums.size());
            vector<int> ans;
            int n = nums.size();

            for (int i = 0; i < n; i++) {
                freq[nums[i]]++;
            }
            for (auto& p : freq) {
                if (p.second > 1){
                    ans.push_back(p.first);
                }    
            }
            return ans;
    }
};
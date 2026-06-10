#include<iostream>
#include<vector>
using namespace std;

// Array contain elements from 1 to n-1 having one duplicant and is sorted and duplicate is last element 

int findDuplicate(vector<int> &arr) 
{
    int ans = 0;
    
    //XOR ing all array elements
    for(int i = 0; i<arr.size(); i++ ) {
    	ans = ans^arr[i];
    }
	
    //XOR [1, n-1]
    for(int i = 1; i<arr.size();i++ ) {
    	ans = ans^i;
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,4};
    cout<<findDuplicate(arr);

    return 0;
}



// leetcode 442

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> ans;

//         for(int i = 0; i < nums.size(); i++){
//             for(int j = i+1; j < nums.size(); j++){
//                 if(nums[i] == nums[j]){
//                     ans.push_back(nums[i]);
//                 }
//             }
//         }
//         return ans;
// }
// };
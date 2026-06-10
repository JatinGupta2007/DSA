#include<iostream>
#include<vector>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);

                //    cout<<i<<" "<<j<<endl;

                }
            }
        }
        return ans;
    }

    int main(){
        vector<int>ques = {0,1,3,4,6,9};
        int target = 4;
        twoSum(ques , target);
    }
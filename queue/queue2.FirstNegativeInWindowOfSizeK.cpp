#include<iostream>
#include<deque>
#include<vector>
using namespace std;
class Solution {

  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> d;
        vector<int> ans;
        
        // Storing negative number for 1st k integers
        for(int  i = 0; i < k; i++){
            if(arr[i] < 0){
                d.push_back(i);
            }
        }
        
        // Checking ans for first k integers
        if(d.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[d.front()]);
        }
        
        
        // For the rest of the pass
        for(int i = k; i < n; i++){
            
            if(!d.empty() && i - d.front() >= k){
                d.pop_front();
            }
            
            if(arr[i] < 0){
                d.push_back(i);
            }
            
            if(d.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(arr[d.front()]);
            }
        }
        return ans;
        
    }
};
#include<iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// BRUTE FORCE
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // Sorting the array so all the duplicates come together
        sort(arr.begin(), arr.end());
        vector<int> ans;

        // Storing count of no of occurences of all the unique elements
        for (int i = 0; i < arr.size();) {
            int j = i + 1;

            int count = 1;

            while (j < arr.size() && arr[i] == arr[j]) {
                count++;
                j++;
            }
            ans.push_back(count);
            i = j;
        }

        // Checking if all the stored occurences are unique or not 
        for (int i = 0; i < ans.size(); i++) {
            for (int j = i + 1; j < ans.size(); j++) {
                if (ans[i] == ans[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};


//OPTIMISED HASH MAP APPROACH

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> freq;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
        }
        
        unordered_set<int> seen; 
        for (auto& p : freq) {
            if(seen.count(p.second)){
                return false;
            }
            seen.insert(p.second);
        }
        return true;
    }
};
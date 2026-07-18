#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    string firstNonRepeating(string &s) {
        unordered_map<char , int> count;
        queue<char> q;
        string ans;
     
        
        for(int i = 0; i < s.length(); i++){
            
            char ch = s[i];
            count[ch]++;
            q.push(ch);
            
            while(!q.empty() && count[q.front()] > 1){
                q.pop();
            }
                
            if(q.empty()){
                ans.push_back('#');
            }
            else{
                ans.push_back(q.front());
            }
        }
    
        return ans;
    }
};
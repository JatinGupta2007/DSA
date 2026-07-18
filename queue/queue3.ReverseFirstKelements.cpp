#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Made a new queue
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if(k > q.size()){
            return q;
        }
        stack<int> s;
        queue<int> ans;

        // first k elements in stack
        for(int i = 0; i < k; i++){
            s.push(q.front());
            q.pop();
        }

        // pushed in new queue after reversing
        while(!s.empty()){
            ans.push(s.top());
            s.pop();
        }

        // pushed remaining elements of the input queue
        while(!q.empty()){
            ans.push(q.front());
            q.pop();
        }
        return ans;
        
    }
};

class Solution1 {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        if(k > n){
            return q;
        }
        stack<int> s;

        // first k elements in stack
        for(int i = 0; i < k; i++){
            s.push(q.front());
            q.pop();
        }

        // pushed in new queue after reversing
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }

        for(int i = 0; i < n - k; i++){
            int element = q.front();
            q.push(element);
            q.pop();
        }
        return q;
    }

       
};
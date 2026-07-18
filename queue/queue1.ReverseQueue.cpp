#include<iostream>
#include <stack>
#include <queue>
using namespace std;

// USING STACK 
class Solution
{
public:
    void reverseQueue(queue<int> &q)
    {
        stack<int> s;

        while (!q.empty())
        {
            s.push(q.front());
            q.pop();
        }

        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
    }
};


// USING RECURSION
class Solution1 {
  public:
    void reverse(queue<int> &q){
        if(q.empty()){
            return;
        }
        
        int front = q.front();
        q.pop();
        reverse(q);
        q.push(front);
        return ;
    }
    
    void reverseQueue(queue<int> &q) {
        reverse(q);
    }
};
int main(){

}
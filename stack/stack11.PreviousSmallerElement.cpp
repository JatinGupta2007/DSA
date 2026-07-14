#include<stack>
#include<vector>
using namespace std;

vector<int> previousSmallerElement(vector<int> &arr, int n){
    
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);

    for(int i = 0; i < n; i++){
        int curr = arr[i];
        while(s.top() > curr ){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;

}
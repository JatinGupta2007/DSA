#include<stack>
#include<vector>
using namespace std;

// This code stores next smallest element  in the array not its index
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);

    for(int i = n-1; i >= 0; i--){
        int curr = arr[i];

        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
   
}
int main(){
    return 0;
}

// TIME COMPLEXITY - O(2N)
// SPACE COMPLEXITY - O(2N)


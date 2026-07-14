#include<stack>
#include<vector>
using namespace std;

// vector<int> nextGreatestElement(vector<int> &arr, int n)
// {
//     stack<int> s;
//     vector<int> ans(n);
//     s.push(__INT_MAX__);

//     for(int i = n-1; i >= 0; i--){
//         int curr = arr[i];

//         while(s.top() <= curr){
//             s.pop();
//         }
        
        
//         if(s.top() == __INT_MAX__){
//             ans[i] = -1;
//         }
//         else{
//             ans[i] = s.top();
//         }


//         s.push(curr);
//     }
//     return ans;
// }


// Circular array is there 

     
vector<int> nextGreatestElementInRotated(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(__INT_MAX__);

    for(int i = (2*n)-1; i >= 0; i--){

        int curr = arr[i%n];

        while(s.top() <= curr){
            s.pop();
        }
        
        
        if(s.top() == __INT_MAX__){
            if(i < n)
            ans[i] = -1;
        }
        else{
            if(i < n)
            ans[i] = s.top();
        }

        s.push(curr);
    }
    return ans;
}
int main(){
    return 0;
}
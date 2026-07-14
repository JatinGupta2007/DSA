#include<stack>
#include<vector>
using namespace std;

// Note - We are going to each pass and arr[i] * (nse - pse - 1) is our area for that i

// OPTIMISED APPROACH (FINDINF NSE AND PSE SEPERATELY AND THEN USING FORMULA)
class Solution {




// CALCULATIN NSE OF a arr[i]
 vector<int> Nse(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(n);

    for(int i = n-1; i >= 0; i--){
        int curr = arr[i];

        while(s.top() != n && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
   
}

// CALCULATIN PSE OF a arr[i]
vector<int> Pse(vector<int> &arr, int n){
    
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);

    for(int i = 0; i < n; i++){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr ){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;

}
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = Nse(heights , n );
        vector<int> pse = Pse(heights , n );
        int max = 0;


        // Perfoming the formula on nse and pse
        for(int i = 0; i < n; i++){
            int l = heights[i];
            int area = (nse[i] - pse[i] - 1) * l ;

            if(area > max){
                max = area;
            }
        }
        return max;
    }
};


// OPTIMISED APPROACH (USING MONOTONIC STACK IN ONE PASS)
class Solution {

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max = 0;
        stack<int> s;

        for(int i = 0; i < n; i++){

            while(!s.empty() && heights[s.top()] > heights[i]){
                int element = s.top();
                s.pop();

                int nse = i;
                int pse = s.empty() ? -1 : s.top();

                int area = heights[element] * (nse - pse - 1);

                if(area > max){
                    max = area;
                }
            }
            s.push(i);
        }

        while(!s.empty()){
            int element = s.top();
            s.pop();
            int nse = n;
            int pse = s.empty() ? -1 : s.top();

            int area = heights[element] * (nse - pse - 1);

            if(area > max){
                 max = area;
            }
        }
        return max;
    }
};
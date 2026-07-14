#include<stack>
#include<vector>
using namespace std;

// BRUTE FORCE 
class Solution {
	public:
	int celebrity(vector<vector<int>> & mat) {
	    
	    int n = mat[0].size();
		vector<int> iKnow(n);
	    vector<int> knowMe(n);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				if (mat[i][j] == 1) {
					iKnow[i]++;
					knowMe[j]++;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (iKnow[i] == 0 && knowMe[i] == n - 1) {
				return i;
			}
		}
		return - 1;
		
	}
};



// STACK METHOD(time but stack take space)
class Solution2 {
	public:
	int celebrity(vector<vector<int>> & mat) {
	    
	    int n = mat[0].size();
	    stack<int> s;
	    
		// put number of people(rows/columns) in a stack 
	    for(int i = 0; i < n; i++){
	        s.push(i);
	    }
	    
		// mark top element and second element
		// Check relation between them (who know whom)
		// eliminate who cannot be celebrity until 1 person remains

	    while(s.size() > 1){
	        int top = s.top();
	        s.pop();
	        
	        if(s.empty()){
	            break;
	        }
	        
	       
	        if(mat[top][s.top()] == 1){
	            continue;
	        }
	        else if(mat[s.top()][top] == 1){
	            s.pop();
	            s.push(top);
	        }
	    }
	    

		// Check the one person who remained is a celebrity or not seperately
	    for(int i = 0; i < n; i++){
	        if(i == s.top()){
	            continue;
	        }
	        if(mat[s.top()][i] == 1 || mat[i][s.top()] == 0){
	            return -1;
	        }
	    }
	    return s.top();
	}
};


// TWO POINTER OPTIMISED APPROACH(space and time)
class Solution3 {
	public:

	int celebrity(vector<vector<int>> & mat) {
	    
	    int n = mat[0].size();
	    
		// take two elements top(first person) and bottom(last person)
	    int top = 0;
	    int bottom = n-1;
	    
	    // Check relation between them (who know whom)
		// eliminate who cannot be celebrity until 1 person remains
	    while(top < bottom ){
	        if(mat[top][bottom] == 1){
	            top++;
	        }
	        else if(mat[bottom][top] == 1){
	            bottom--;
	        }
	        else{
	            bottom--;
	        }
	    }
	    
		// Check the one person who remained is a celebrity or not seperately 
	    for(int k = 0; k < n; k++){
	        if(top == k){
	            continue;
	        }
	        if(mat[top][k] == 1 || mat[k][top] == 0){
	            return -1;
	        }
	    }
	    return top;
	}
	   
};


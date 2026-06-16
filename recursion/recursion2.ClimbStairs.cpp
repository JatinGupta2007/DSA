#include <iostream>
using namespace std;


// One can only climb  1 or 2 stairs at a time.
// ex- 3 stairs can be climber by (1,1,1) (1,2) (2,1) 

int countDistinctWays(int n) {    // n = number of stairs


    // BASE CASE
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }

    // RECURSIVE RELATION
    int ans = countDistinctWays(n-1) + countDistinctWays(n-2);
    return ans;
    
}
int main(){}
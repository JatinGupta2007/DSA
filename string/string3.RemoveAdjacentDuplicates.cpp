<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;

class Solution1
{
public:
    // Not optimised (worst case - O(N2))

    string removeDuplicates(string s)
    {
        int i = 0;
        while (s.length() != 0 && i <= (int)s.length() - 2)
        {
            // s.length() gives a unsigned integer as ans so it cannot be negative. so when
            // length is 0 it cannot become -2 , and gives a large int as ans , to solve this

            if (s[i] == s[i + 1])
            {
                s.erase(i, 2);
                i = 0;
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};


// Optimised stack based approach (string is working as stack here , we can use stack too but it will give reverse ans 
// so we will have to reverse it then )

class Solution2 {
public:
    string removeDuplicates(string s) {
        string result;
        for (char c : s) {
            
            if (result.empty() == 0 && result.back() == c) {
                result.pop_back();
            }

            else {
                result.push_back(c);
            }
        }
        return result;
    }
};
=======
class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;
        while(s.length() != 0  && i <= (int)s.length() - 2){     // s.length() gives a unsigned integer as ans so it cannot be negative. so when 
                                                                 // length is 0 it cannot become -2 , and gives a large int as ans , to solve this
            
            if(s[i] == s[i+1]){
            s.erase(i , 2);
            i = 0;
        }
        else{
            i++;
        }
     }
        return s;
        
    }
};
>>>>>>> 611c40ef587e1382bcbdf1013f22bbf58afdfeec

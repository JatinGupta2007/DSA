#include <iostream>
#include <string>
using namespace std;

// Nice approach (using string functions)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() != 0 && s.find(part) < s.length()){
            s.erase(s.find(part) , part.length());
        }
        return s;
    }
};


// Using string as stack kind of approach (optimised) (using string functions) 
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st;
        int p = part.size();

        for (char c : s) {
            st.push_back(c);

            // check if last p characters match 'part'
            if (st.size() >= p && st.substr(st.size() - p) == part) {
                st.erase(st.size() - p , p);
            }
        }
        return st;
    }
};

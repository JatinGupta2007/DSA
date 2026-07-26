#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Optimised approach (counting frequancy)
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;
            
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return false;
        }
        return true;
    }
};


// Jugaad approach

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());

        for(int i = 0; i < max(s.length() , t.length()); i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }

       
};
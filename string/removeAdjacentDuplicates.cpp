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
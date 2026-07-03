#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:

    bool match(char ch , char top){
        if( (ch == '(' && top == ')') || (ch == '[' && top == ']') || (ch == '{' && top == '}') ){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValid(string s) {

       stack<char> val;

       for(int i = 0; i < s.length(); i++){

        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            val.push(ch);
        }

        else{
 
            if(!val.empty()){
                char top = val.top();
                if(match(top , ch)){
                    val.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
       }
       

       if(val.empty()){
          return true;
       }
       return false;
        
    }
};

int main(){
    return 0;
}
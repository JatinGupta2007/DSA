#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> check;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){

            check.push(ch);
        }

        else{

            if(ch == ')'){
                char top = check.top();
                
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    
                    while(check.top() != '('){
                    check.pop();
                    }
                    check.pop();
                }
                else{
                    return true;
                }
            }

        }
    }
    return false;
}
int main(){
    return 0;
}

#include<iostream>
using namespace std;

bool checkPal(string s  , int start, int end){
    if(start > end){
        return true;
    }

    if(s[start] != s[end]){
        return false;
    }
    else if(s[start] == s[end]){
        start++;
         end--;
    }
    return checkPal(s , start , end);

}
int main()
{
    string s = "abcddcbak";
    int start = 0 , end = s.length() - 1;
    bool ans = checkPal(s , start , end);
    cout<<ans;
return 0;
}
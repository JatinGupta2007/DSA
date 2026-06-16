#include<iostream>
using namespace std;

void reverse(string &s  , int start, int end){
    if(start > end){
        return;
    }

    swap(s[start] , s[end]);
    start++;
    end--;
    reverse(s , start , end);

}
int main()
{
    string s = "abcde";
    int start = 0 , end = s.length() - 1;
    reverse(s , start , end);
    cout<<s;
return 0;
}
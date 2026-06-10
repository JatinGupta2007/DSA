#include<iostream>
#include<string>
using namespace std;

char GetMaxChar(string s){
    int arr[26] = {0};
    int num = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
             num = s[i] - 'a';
        }
         else{
             num = s[i] - 'A';
        }
        arr[num]++;
    }

    int max = -1,ans=-1;
    for(int j = 0; j<26; j++){
        if(max < arr[j]){
            ans = j;
            max = arr[j];
         }
    }

    char finalAns = ans + 'a';
    return finalAns ;
}
int main()
{
    string st;
    cin>>st;
    cout<<GetMaxChar(st);


return 0;
}
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

// Optimised approach (case insensitive) (only works for alphabets)
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

// Hash map approach (optimised , case sensitive , work for any char)
char GetMaxChar2(string s){
    unordered_map<char , int> arr;

    for(int i = 0; i < s.length(); i++){
        arr[s[i]]++;
    }

    int max = -1;
    char ans = '\0';

    for(auto p : arr){
        if(p.second > max){
            max = p.second;
            ans = p.first;
        }
    }
    return ans ;
}
int main()
{
    string st;
    cout<<"Enter the string: ";
    cin>>st;
    cout<<GetMaxChar2(st);


return 0;
}
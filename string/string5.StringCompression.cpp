<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Optimised , nice approach
class Solution
{
public:
    int compress(vector<char> &arr)
    {
        string s;
        int count = 1;

        for (int i = 1; i <= arr.size(); i++)
        {
            if (i < arr.size() && arr[i] == arr[i - 1])
            {
                count++;
            }
            else
            {
                s.push_back(arr[i - 1]);
                if (count > 1)
                {
                    s += to_string(count); // handles any size count
                }
                count = 1;
            }
        }

        arr.assign(s.begin(), s.end());
        return arr.size();
    }
};


// 2 pointer optimised approach
class Solution
{
public:
    int compress(vector<char> &arr)
    {
=======
// class Solution {
// public:
//     int compress(vector<char>& arr) {

//         string s;
//         int count = 1;

//         for(int i = 0; i < arr.size();){
//             char k = arr[i];
//             if(i != arr.size() - 1){
//             i++;
//             }
//             if(arr[i] == k){
//                 count++;
//             }
//             else{
//                 if(count > 1 && count < 10){
//                 s.push_back(arr[i-1]);
//                 s += to_string(count);

//                 count = 1;
//             }
//                 else if(count == 1){
//                     s.push_back(arr[i-1]);
//                     count = 1;
//                 } 
//                 else if(count >= 10){
//                     int num = count/10;
//                     int num2 = count%10;
//                       s.push_back(arr[i-1]);
//                       s += to_string(num);
//                        s += to_string(num2);
//                 }

//             }
//         }

//           arr.assign(s.begin(), s.end());  


//         return arr.size();

//     }
// };


class Solution {
public:
    int compress(vector<char>& arr) {
>>>>>>> 611c40ef587e1382bcbdf1013f22bbf58afdfeec
        int ansIndex = 0;
        int i = 0;
        int n = arr.size();

<<<<<<< HEAD
        while (i < n)
        {
            int j = i + 1;
            while (j < n && arr[i] == arr[j])
            {
=======
        while(i < n){
            int j = i + 1;
            while(j < n && arr[i] == arr[j]){
>>>>>>> 611c40ef587e1382bcbdf1013f22bbf58afdfeec
                j++;
            }

            arr[ansIndex++] = arr[i];
<<<<<<< HEAD
            int count = j - i;

            if (count > 1)
            {
                string cnt = to_string(count);
                for (char ch : cnt)
                {
=======
            int count = j-i;

            if(count > 1){
                string cnt = to_string(count);
                for( char ch : cnt){
>>>>>>> 611c40ef587e1382bcbdf1013f22bbf58afdfeec
                    arr[ansIndex++] = ch;
                }
            }
            i = j;
        }
        return ansIndex;
<<<<<<< HEAD
    }
};
=======
    }    
};


     
>>>>>>> 611c40ef587e1382bcbdf1013f22bbf58afdfeec

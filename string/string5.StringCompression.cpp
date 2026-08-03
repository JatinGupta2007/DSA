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
        int ansIndex = 0;
        int i = 0;
        int n = arr.size();

        while (i < n)
        {
            int j = i + 1;
            while (j < n && arr[i] == arr[j])
            {
                j++;
            }

            arr[ansIndex++] = arr[i];
            int count = j - i;

            if (count > 1)
            {
                string cnt = to_string(count);
                for (char ch : cnt)
                {
                    arr[ansIndex++] = ch;
                }
            }
            i = j;
        }
        return ansIndex;
    }
};

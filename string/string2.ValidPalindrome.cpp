#include <iostream>
#include <string>
using namespace std;
class Solution
{
private:
    bool valid(char ch)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            return true;
        }
        return false;
    }

    char lowerCase(char ch)
    {

        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - 'A' + 'a';
            return ch;
        }
        return ch;
    }

public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i < j)
        {
            if (valid(s[i]) == 1 && valid(s[j]) == 1)
            {
                if (lowerCase(s[i]) != lowerCase(s[j]))
                {
                    return false;
                }
                i++;
                j--;
            }
            else if (valid(s[i]) == 0)
            {
                i++;
            }
            else if (valid(s[j]) == 0)
            {
                j--;
            }
        }
        return true;
    }
};
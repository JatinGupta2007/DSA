#include <iostream>
#include <cmath>
using namespace std;

int convertBinary(int n)
{
    int num = 0;

    for (int i = 0; n != 0; i++)
    {
        num = num + (pow(10, i) * (n & 1));
        n = (n >> 1);
    }
    return num;
}

int convertBinaryNegative(int n)
{

    int num = 0;
    int num2 = 0;

    for (int i = 0; n != 0; i++)
    {
        num = num + (pow(10, i) * (n & 1));
        n = (n >> 1);
    }

    for (int i = 0; num != 0; i++)
    {
        if (num & 1)
        {
            num2 = num2 + (pow(10, i) * 0);
        }
        else
        {
            num2 = num2 + (pow(10, i) * 1);
        }
    }
    return num2;
}

int main()
{
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    cout << convertBinary(n);
    // cout<<convertBinaryNegative(-n);

    return 0;
}
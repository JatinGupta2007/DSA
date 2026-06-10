#include <iostream>
#include <cmath>
using namespace std;

int convertDecimal(int n)
{
    int num = 0;
    int i = 0;
    while (n != 0)
    {
        int j = n % 10;
        num = num + (pow(2, i) * j);
        n = (n / 10);
        i++;
    }
    return num;
}
int main()
{

    int n;
    cout << "Enter value of n: ";
    cin >> n;
    cout << convertDecimal(n);
    return 0;
}

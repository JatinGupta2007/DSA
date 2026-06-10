#include <iostream>
using namespace std;

int squareRoot(int num)
{
    int min = 0;
    int max = num;
    int ans = 0;
    while (min <= max)
    {
        int mid = (max + min) / 2;
        if (mid * mid < num)
        {
            ans = mid;
            min = mid + 1;
        }
        else if (mid * mid > num)
        {
            max = mid - 1;
        }
        else if (mid * mid == num)
        {
            return mid;
        }
    }
    return ans;
}


double morePrecision(int n, int precision, int tempSol) {

    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}
int main()
{

    cout << squareRoot(113)<<endl;
    cout << morePrecision(113,2,squareRoot(113));

    return 0;
}


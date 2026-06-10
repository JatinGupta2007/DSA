#include <iostream>
#include <vector>
using namespace std;

// n is number of books
// m is number of students
// arr contain n books and arr[i] contain number of pages in book
// arr is in increasing order

// each student should get 1 book
// each book should be alloted
// it should be alloted in  such a manner that max pages one will get should be minimum
// book can be alloted in contious order only and (only till end this countinous order will be followed

bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studentCount = 1; // start with first student
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            pageSum = arr[i];
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    int min = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
    }
    int max = sum;
    int mid = (min + max) / 2;
    int ans = 0;

    while (min <= max)
    {
        mid = (min + max) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> array = {10, 20, 30, 40};
    cout << allocateBooks(array, array.size(), 2);

    return 0;
}
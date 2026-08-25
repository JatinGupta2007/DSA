#include <iostream>
#include<climits>
#include <vector>
using namespace std;

// n is number of books
// m is number of students
// arr contain n books and arr[i] contain number of pages in book
// arr is in increasing order

// each student should get atleast 1 book
// each book should be alloted
// it should be alloted in  such a manner that max pages one will get should be minimum
// book can be alloted in contious order only and (only till end this countinous order will be followed)

bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int studentCount = 1; // start with first student
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if(pageSum + arr[i] <= mid){
            pageSum = pageSum + arr[i];
        }

        else{
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

int allocateBooks(vector<int> &arr, int n, int m)
{

    if(m > n){          // students more than books 
        return -1;
    }

    int sum = 0;
    int maxNum = INT_MIN;
    for (int i = 0; i < arr.size(); i++){
        if(arr[i] > maxNum){
            maxNum = arr[i];
        }
        sum = sum + arr[i];
    }

    int low = maxNum;
    int high = sum;
    
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> array = {25, 46, 28, 49, 24};
    cout << allocateBooks(array, array.size(), 4);

    return 0;
}
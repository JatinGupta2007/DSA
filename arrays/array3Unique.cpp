#include <iostream>
#include <unordered_map>
using namespace std;

// Optimised hash map approach

int findUnique(int arr[], int n) {
    unordered_map<int,int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    for (auto &p : freq) {
        if (p.second == 1) return p.first;
    }
    return -1; // no unique element
}




// OPTIMISED SOLUTION (O(N))
int main()
{
    int arr[11] = {9, 1, 1, 2, 2};
    int size = 5;
    int Ans = 0;
    for (int i = 0; i < size; i++)
    {
        Ans = Ans ^ arr[i];
    }
    cout << Ans;
    return 0;
}
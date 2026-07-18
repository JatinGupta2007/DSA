#include<iostream>
#include<vector>
using namespace std;


// Making a new array (taking extra space)
// question has given nums1 (m + n) space so we don't have to make a extra array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i = 0;
    int j = 0;
    int count = 0;
    vector<int> nums3(m+n);
    while(i < m && j < n){
        if(nums1[i] < nums2[j] && i<m){
            nums3[count] = nums1[i];
            i++;
            count++;
        }
        else{
            nums3[count] = nums2[j];
            j++;
            count++;
        }
    }

    // Copy remaining elements safely
        while (i < m) nums3[count++] = nums1[i++];
        while (j < n) nums3[count++] = nums2[j++];

    nums1 = nums3;
}
};



// Without extra space approach'

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // last valid element in nums1
        int j = n - 1;       // last element in nums2
        int k = m + n - 1;   // last position in nums1

        // Merge from the back
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining elements from nums2 (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        // No need to copy from nums1, they’re already in place
    }
};


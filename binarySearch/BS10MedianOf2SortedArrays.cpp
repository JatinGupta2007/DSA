#include<iostream>
#include<vector>
using namespace std;


// Better for understanding , 2 passes
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    
                
        int n = nums1.size();
        int m = nums2.size();

        if(n > m){
            return findMedianSortedArrays(nums2, nums1);
        }

        int total = n + m;

        int low = 0;
        int high = n;

        if (total % 2 == 0) {
            while (low <= high) {
                int half = (n + m) / 2;
                int mid = low + (high - low) / 2;

                int left1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
                int right1 = (mid == n) ? INT_MAX : nums1[mid];
                int left2 = (half - mid == 0) ? INT_MIN : nums2[half - mid - 1];
                int right2 = (half - mid == m) ? INT_MAX : nums2[half - mid];

                if (left1 <= right2 && left2 <= right1) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } 
                else if (left1 > right2) {
                    high = mid - 1;
                } 
                else {
                    low = mid + 1;
                }
            }
        }

        else {

            while (low <= high) {
                int half = ((n + m) / 2) + 1;
                int mid = low + (high - low) / 2;
                int left1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
                int right1 = (mid == n) ? INT_MAX : nums1[mid];
                int left2 = (half - mid == 0) ? INT_MIN : nums2[half - mid - 1];
                int right2 = (half - mid == m) ? INT_MAX : nums2[half - mid];

                if (left1 <= right2 && left2 <= right1) {

                    return (max(left1, left2));

                } 
                else if (left1 > right2) {
                    high = mid - 1;
                } 
                else {
                    low = mid + 1;
                }
            }
        }
        return 0;
    }
};




// Single pass


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size(), m = nums2.size();
        int total = n + m;
        int half = total / 2;

        int low = 0, high = n;
        while(low <= high) {
            int mid = (low + high) / 2;
            int left1 = (mid == 0) ? INT_MIN : nums1[mid-1];
            int right1 = (mid == n) ? INT_MAX : nums1[mid];
            int left2 = (half - mid == 0) ? INT_MIN : nums2[half-mid-1];
            int right2 = (half - mid == m) ? INT_MAX : nums2[half-mid];

            if(left1 <= right2 && left2 <= right1) {
                if(total % 2 == 0) {
                    return (max(left1,left2) + min(right1,right2)) / 2.0;
                } else {
                    return min(right1,right2);
                }
            }
            else if(left1 > right2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return 0.0;
    }
};
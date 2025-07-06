#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;

        vector<int> nums3;

        // Merge two sorted arrays
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                nums3.push_back(nums1[i++]);
            } else {
                nums3.push_back(nums2[j++]);
            }
        }

        // Copy remaining elements
        while (i < n) {
            nums3.push_back(nums1[i++]);
        }

        while (j < m) {
            nums3.push_back(nums2[j++]);
        }

        int k = nums3.size();
        // Return median
        if (k % 2 != 0) {
            return nums3[k / 2];
        } else {
            return (nums3[k / 2] + nums3[(k / 2) - 1]) / 2.0;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median is: " << median << endl;

    return 0;
}

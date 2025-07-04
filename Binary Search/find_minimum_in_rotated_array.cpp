//153. Find Minimum in Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // If mid element is greater than the last, min must be in right part
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            }
            // Else, the min is in the left part including mid
            else {
                e = mid;
            }
        }

        // At the end, s == e and points to the minimum element
        return nums[s];
    }
};

int main() {
    vector<int> nums = {11, 13, 15, 17};  // You can test with any rotated sorted array
    Solution sol;
    int result = sol.findMin(nums);
    cout << "Minimum element is: " << result << endl;
    return 0;
}

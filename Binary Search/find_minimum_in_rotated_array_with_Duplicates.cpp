//154. Find Minimum in Rotated Sorted Array II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] > nums[e]) {
                s = mid + 1;
            }
            else if (nums[mid] < nums[e]) {
                e = mid;
            }
            else {
                e--; // nums[mid] == nums[e], can't decide, reduce e
            }
        }

        cout << "Pivot index: " << s << endl; // Optional debug
        return nums[s];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,1,1,1,1,1,1,2,1,1,1,1}; // Rotated with duplicates
    int result = sol.findMin(nums);
    cout << "Minimum element: " << result << endl;
    return 0;
}

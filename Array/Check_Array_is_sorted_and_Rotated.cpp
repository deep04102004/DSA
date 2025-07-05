//1752. Check if Array Is Sorted and Rotated
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                count++;
            }
        }

        // Also check last element vs first
        if (nums[n - 1] > nums[0]) {
            count++;
        }

        return (count <= 1);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 4, 5, 1, 2};  // Rotated sorted → true
    // vector<int> nums = {2, 1, 3, 4};  // Not valid → false

    bool result = sol.check(nums);

    cout << (result ? "true" : "false") << endl;

    return 0;
}

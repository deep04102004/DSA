//164. Maximum Gap
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if (n < 2) {
            return 0;
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            ans = max(ans, diff);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {3, 6, 9, 1};  // Test case
    
    int result = sol.maximumGap(nums);
    
    cout << "Maximum gap: " << result << endl;

    return 0;
}

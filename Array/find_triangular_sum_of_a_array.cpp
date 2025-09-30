//2221. Find Triangular Sum of an Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> ans;
            for (int i = 0; i < nums.size() - 1; i++) {
                ans.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = move(ans);
        }
        return nums[0];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 5, 3, 6, 4};
    int result = sol.triangularSum(nums);

    cout << "Triangular Sum: " << result << endl;  // Output: 8

    return 0;
}

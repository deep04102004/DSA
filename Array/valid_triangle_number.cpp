//611. Valid Triangle Number
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 4};
    cout << sol.triangleNumber(nums) << endl; 
    return 0;
}

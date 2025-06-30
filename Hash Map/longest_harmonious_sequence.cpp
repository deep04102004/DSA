//594. Longest Harmonious Subsequence
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int &a : nums) mp[a]++;
        
        int maxi = 0;
        for (auto &b : mp) {
            if (mp.count(b.first + 1)) {
                maxi = max(maxi, mp[b.first] + mp[b.first + 1]);
            }
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    int result = sol.findLHS(nums);
    cout << "Longest Harmonious Subsequence length: " << result << endl;
    return 0;
}

//3349. Adjacent Increasing Subarrays Detection I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false; // at least 2 elements needed

        int inc = 1;       // length of current increasing run
        int previnc = 0;   // length of previous increasing run
        int maxlen = 0;    // maximum valid run combination

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                // still increasing
                inc++;
            } else {
                // increasing sequence broke
                previnc = inc;
                inc = 1;
            }

            // compute best combined valid run length
            // (either one long run, or two consecutive runs)
            maxlen = max(maxlen, max(inc >> 1, min(previnc, inc)));

            if (maxlen >= k)
                return true;
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums4 = {1, 2, 3, 4, 5};
    int k4 = 2;
    cout <<  (sol.hasIncreasingSubarrays(nums4, k4) ? "true" : "false") << endl;

    return 0;
}


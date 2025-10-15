//3350. Adjacent Increasing Subarrays Detection II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int inc = 1;       // length of current increasing sequence
        int preinc = 0;    // length of previous increasing sequence
        int k = 0;         // final result (max value)
        int m = 0;         // temporary max value

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
            } else {
                preinc = inc;
                inc = 1;
            }

            // calculate m for each step
            m = max(m, max(inc >> 1, min(inc, preinc)));

            // store the maximum
            if (k < m) k = m;
        }

        return k;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = obj.maxIncreasingSubarrays(nums);
    cout << "Maximum value of k: " << result << endl;

    return 0;
}

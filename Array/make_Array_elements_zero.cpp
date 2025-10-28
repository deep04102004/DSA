//3354. Make Array Elements Equal to Zero
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) continue; // can only start where nums[i] == 0

            for (int dir : {-1, 1}) { // test both directions
                vector<int> temp = nums;
                int curr = i;
                int d = dir;

                while (curr >= 0 && curr < n) {
                    if (temp[curr] == 0) {
                        curr += d; // move in same direction
                    } else {
                        temp[curr]--; // decrement
                        d = -d;       // reverse direction
                        curr += d;    // move in new direction
                    }
                }

                bool allzero = true;
                for (int val : temp) {
                    if (val != 0) {
                        allzero = false;
                        break;
                    }
                }

                if (allzero) result++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 2, 0, 3};

    cout << "Output: " << sol.countValidSelections(nums) << endl;
    return 0;
}

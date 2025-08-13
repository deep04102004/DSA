//Tywin's War Strategy (GFG).
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> extra; // store soldiers needed to make troop lucky
        int cnt = 0;       // count of already lucky troops

        // Step 1: Count already lucky troops and calculate extra soldiers needed for others
        for (int i = 0; i < n; i++) {
            if (arr[i] % k == 0) {
                cnt++;
            } else {
                extra.push_back(k - arr[i] % k);
            }
        }

        // Step 2: Calculate how many lucky troops we need
        int required = (n + 1) / 2; // ceil(n / 2)
        if (cnt >= required) {
            return 0; // already have enough lucky troops
        }

        // Step 3: Sort to find cheapest upgrades
        sort(extra.begin(), extra.end());

        // Step 4: Pick the smallest costs to upgrade troops
        int m = required - cnt;
        int cost = 0;
        for (int i = 0; i < m; i++) {
            cost += extra[i];
        }

        return cost;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2, 3, 4, 5};
    int k = 3;

    cout << sol.minSoldiers(arr, k) << "\n"; // Expected output: 1

    return 0;
}

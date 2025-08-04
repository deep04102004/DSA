//2561. Rearranging Fruits
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;

        for (int b1 : basket1)
            mp[b1]++;
        for (int b2 : basket2)
            mp[b2]--;

        vector<int> temp;

        // Find the global minimum element across both baskets
        int minele = *min_element(basket1.begin(), basket1.end());
        minele = min(minele, *min_element(basket2.begin(), basket2.end()));

        // Check frequencies and build swap list
        for (auto& a : mp) {
            int fruit = a.first;
            int freqDiff = a.second;

            // If odd difference, impossible to balance
            if (freqDiff % 2 != 0) {
                return -1;
            }

            // Add half the extra elements to temp (half from one basket)
            for (int i = 0; i < abs(freqDiff) / 2; i++) {
                temp.push_back(fruit);
            }
        }

        // Sort to bring smaller-cost swaps first
        sort(temp.begin(), temp.end());

        long long ans = 0;
        int n = temp.size();

        // Only half the swaps are needed (each swap fixes two mismatches)
        for (int i = 0; i < n / 2; i++) {
            ans += min(temp[i], 2 * minele); // choose cheaper between direct and indirect swap
        }

        return ans;
    }
};

// Test case
int main() {
    Solution sol;

    vector<int> basket1 = {84, 80, 43, 8, 80, 88, 43, 14, 100, 88};
    vector<int> basket2 = {32, 32, 42, 68, 68, 100, 42, 84, 14, 8};

    cout << "Minimum cost to rearrange: " << sol.minCost(basket1, basket2) << endl;

    return 0;
}

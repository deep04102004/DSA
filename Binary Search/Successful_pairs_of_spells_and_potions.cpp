//2300. Successful Pairs of Spells and Potions
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Step 1: Sort the potions array for binary search
        sort(potions.begin(), potions.end());
        vector<int> ans;

        // Step 2: For each spell, find the number of successful pairs
        for (int s : spells) {
            long long required = (success + s - 1) / s; // Minimum potion value needed
            auto it = lower_bound(potions.begin(), potions.end(), required); // Binary search
            ans.push_back(potions.end() - it); // Count of successful potions
        }

        return ans;
    }
};

int main() {
    // Example input
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

   
    Solution sol;

    vector<int> result = sol.successfulPairs(spells, potions, success);

    cout << "Successful pairs for each spell: ";
    for (int x : result) {
        cout << x << " ";         // output: [4,0,3]
    }
    cout << endl;

    return 0;
}

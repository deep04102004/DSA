//347. Top K Frequent Elements
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        priority_queue<pair<int, int>> q;
        
        vector<int> ans;

        // Count frequency of each number
        for (int& a : nums) {
            mp[a]++;
        }

        // Push {frequency, number} into max heap
        for (auto& b : mp) {
            q.push({b.second, b.first});
        }

        // Get top k elements
        for (int i = 0; i < k && !q.empty(); i++) {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test case
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);

    // Output result
    cout << "Top " << k << " frequent elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

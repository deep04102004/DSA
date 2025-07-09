//215. Kth Largest Element in an Array
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Max heap (by default in C++)
        priority_queue<int> q;

        // Push all elements into the heap
        for (int& a : nums) {
            q.push(a);
        }

        // Pop k-1 elements to reach the kth largest
        int result;
        for (int i = 1; i <= k; i++) {
            result = q.top();
            q.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 2, 1, 5, 6, 4}; // Example array
    int k = 2;  // Find 2nd largest element

    int kthLargest = sol.findKthLargest(nums, k);

    cout << "The " << k << "th largest element is: " << kthLargest << endl;

    return 0;
}

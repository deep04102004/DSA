#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<int> dq;   // stores indices of negative numbers
        vector<int> ans;

        // Process first window
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                dq.push_back(i);
            }
        }

        // Answer for first window
        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }

        // Process rest of the windows
        for (int i = k; i < arr.size(); i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }

            // Add current element if it is negative
            if (arr[i] < 0) {
                dq.push_back(i);
            }

            // Store answer for this window
            if (!dq.empty()) {
                ans.push_back(arr[dq.front()]);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};

// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    cout << "Input Array: ";
    printVector(arr);

    vector<int> result = sol.firstNegInt(arr, k);

    cout << "First Negative in every window of size " << k << ": ";
    printVector(result);

    return 0;
}
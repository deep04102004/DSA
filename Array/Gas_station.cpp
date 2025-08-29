#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int deficit = 0;   // total shortage across failed attempts
        int balance = 0;   // current gas balance
        int start = 0;     // candidate starting station
        
        for (int i = 0; i < gas.size(); i++) {
            balance += gas[i] - cost[i];
            
            // If we can't reach the next station
            if (balance < 0) {
                deficit += balance;  // record shortage
                start = i + 1;       // try starting from next station
                balance = 0;         // reset balance
            }
        }
        
        // If total gas >= total cost, return valid start, otherwise -1
        if (deficit + balance >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Start station: " << sol.startStation(gas1, cost1) << endl; // Output: 3

    // Example 2
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Start station: " << sol.startStation(gas2, cost2) << endl; // Output: -1

    return 0;
}

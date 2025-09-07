//1304. Find N Unique Integers Sum up to Zero
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        // Construct pairs of +i and -i
        for (int i = 1; i <= n / 2; i++) {
            ans.push_back(i);
            ans.push_back(-i);
        }

        // If n is odd, add 0 to balance
        if (n & 1) {
            ans.push_back(0);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n = 5;  // test case
    vector<int> result = sol.sumZero(n);

    cout << "Array of " << n << " numbers that sum to zero: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

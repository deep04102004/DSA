//66. Plus One
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        int sum = 0;

        for (int i = n - 1; i >= 0 && carry > 0; i--) {
            sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};

int main() {
    Solution sol;

    vector<int> digits = {9, 9, 9}; // Example input

    vector<int> result = sol.plusOne(digits);

    for (int num : result) {
        cout << num;
    }

    cout << endl;
    return 0;
}

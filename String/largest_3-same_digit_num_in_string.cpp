//2264. Largest 3-Same-Digit Number in String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char maxi = '\0';
        for (int i = 0; i < n - 2; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                maxi = max(maxi, num[i]);
            }
        }
        return maxi == '\0' ? "" : string(3, maxi);
    }
};

int main() {
    Solution sol;
    string num = "677733";
    cout << sol.largestGoodInteger(num) << endl; // Output: 777
    return 0;
}

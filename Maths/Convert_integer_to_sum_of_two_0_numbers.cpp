//1317. Convert Integer to the Sum of Two No-Zero Integers
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int j = n - i;
            // Convert both numbers into string and check for '0'
            if ((to_string(i) + to_string(j)).find('0') == string::npos) {
                return {i, j};
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    int n = 11; // test case
    vector<int> ans = sol.getNoZeroIntegers(n);

    cout << "For n = " << n << ", pair is: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

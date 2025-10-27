//2125. Number of Laser Beams in a Bank~
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;

        for (string& s : bank) {
            int count = 0;
            for (char& ch : s) {
                if (ch == '1') {
                    count++;
                }
            }

            if (count != 0) {
                ans += prev * count;
                prev = count;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> bank1 = {"011001", "000000", "010100", "001000"};
    cout << "Number of beams (Example 1): " << sol.numberOfBeams(bank1) << endl;

    return 0;
}

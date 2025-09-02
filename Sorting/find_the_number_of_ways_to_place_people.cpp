//3025. Find the Number of Ways to Place People I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Sort: x ascending, if tie then y descending
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = points.size(), result = 0;

        for (int i = 0; i < n; i++) {
            int top = points[i][1];
            int bot = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                int y = points[j][1];
                if (bot < y && y <= top) {
                    result++;
                    bot = y;
                    if (bot == top) break; // no further valid y possible
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test case
    vector<vector<int>> points = {{3,1},{1,3},{1,1}};
    cout << sol.numberOfPairs(points) << endl; 

    return 0;
}

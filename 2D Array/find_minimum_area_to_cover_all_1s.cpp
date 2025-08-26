//3195. Find the Minimum Area to Cover All Ones I
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxrow = 0, minrow = n;
        int maxcol = 0, mincol = m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    minrow = min(minrow, i);
                    maxrow = max(maxrow, i);
                    mincol = min(mincol, j);
                    maxcol = max(maxcol, j);
                }
            }
        }
        return (maxrow - minrow + 1) * (maxcol - mincol + 1);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    cout << sol.minimumArea(grid) << endl; 
    // Expected output: 6 (rectangle covering rows 1-2 and cols 1-3)

    return 0;
}

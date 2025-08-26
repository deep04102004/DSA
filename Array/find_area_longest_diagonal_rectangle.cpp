//3000. Maximum Area of Longest Diagonal Rectangle
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxdiagonal = 0, maxarea = 0;

        for (const auto& dim : dimensions) {
            int l = dim[0], w = dim[1];
            int diagonal = l * l + w * w; // using squared diagonal to avoid sqrt
            int area = l * w;

            if (diagonal > maxdiagonal) {
                maxdiagonal = diagonal;
                maxarea = area;
            } else if (diagonal == maxdiagonal) {
                maxarea = max(maxarea, area);
            }
        }
        return maxarea;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> dimensions = {
        {9, 3},
        {8, 6}
    };

    cout << sol.areaOfMaxDiagonal(dimensions) << endl;
    // Expected output: 48 (second rectangle has larger diagonal)

    return 0;
}

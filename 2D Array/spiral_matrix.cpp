//54. Spiral Matrix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n * m;

        int count = 0;
        int top = 0, bottom = n - 1, left = 0, right = m - 1;

        vector<int> ans;

        while (count < total) {
            for (int i = left; i <= right && count < total; i++) {
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;

            for (int i = top; i <= bottom && count < total; i++) {
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;

            for (int i = right; i >= left && count < total; i--) {
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;

            for (int i = bottom; i >= top && count < total; i--) {
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example input matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Get spiral order
    vector<int> result = sol.spiralOrder(matrix);

    // Print result
    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

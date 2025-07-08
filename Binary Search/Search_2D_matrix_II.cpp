//240. Search a 2D Matrix II
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int rowindex = 0, colindex = m - 1;

        while (rowindex < n && colindex >= 0) {
            int element = matrix[rowindex][colindex];

            if (element == target) {
                return true;
            }
            else if (element < target) {
                rowindex++;
            }
            else {
                colindex--;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    
    int target = 5;

    Solution sol;
    if (sol.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}

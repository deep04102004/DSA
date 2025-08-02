//118. Pascal's Triangle
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);  // Initialize row with 1s
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];  // Fill middle elements
            }
            ans.push_back(row);
        }

        return ans;
    }
};

int main() {
    int numRows = 5;  // You can change this to test other cases
    Solution sol;
    vector<vector<int>> result = sol.generate(numRows);

    // Print Pascal's Triangle
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

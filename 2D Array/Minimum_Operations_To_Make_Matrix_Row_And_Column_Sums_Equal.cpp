//Make Matrix Beautiful (gfg).

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int balanceSums(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<int> rowsum(n, 0);
    vector<int> colsum(n, 0);

    // Calculate row and column sums
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rowsum[i] += mat[i][j];
            colsum[j] += mat[i][j];
        }
    }

    // Find the maximum row/column sum
    int maxsum = 0;
    for (int i = 0; i < n; i++) {
        maxsum = max(maxsum, rowsum[i]);
        maxsum = max(maxsum, colsum[i]);
    }

    // Total sum of matrix
    int totalsum = 0;
    for (int i = 0; i < n; i++) {
        totalsum += rowsum[i]; // Or use colsum[i], both are same
    }

    // Minimum operations required
    return (n * maxsum) - totalsum;
}

int main() {
    // Sample 3x3 matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 2, 3},
        {3, 2, 1}
    };

    int operations = balanceSums(mat);
    cout << "Minimum number of operations to make matrix beautiful: " << operations << endl;

    return 0;
}

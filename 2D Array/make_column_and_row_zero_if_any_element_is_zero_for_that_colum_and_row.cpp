#include <iostream>
#include<vector>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    // Make a copy of the matrix
    vector<vector<int>> mat1 = mat;

    // Traverse the original matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                // Zero out the entire column in mat1
                for (int k = 0; k < n; k++) {
                    mat1[k][j] = 0;
                }
                // Zero out the entire row in mat1
                for (int l = 0; l < m; l++) {
                    mat1[i][l] = 0;
                }
            }
        }
    }

    // Copy back to original matrix
    mat = mat1;
}

int main() {
    vector<vector<int>> mat = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    setMatrixZeroes(mat);

    for (auto &row : mat) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}

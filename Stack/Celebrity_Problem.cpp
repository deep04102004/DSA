#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
private:
    // Helper function: returns true if a knows b
    bool know(vector<vector<int>>& mat, int a, int b) {
        return mat[a][b] == 1;
    }

public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> st;

        // Push all persons into the stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Eliminate non-celebrities
        while (st.size() > 1) {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if (know(mat, a, b)) {
                // a knows b => a can't be celeb
                st.push(b);
            } else {
                // a doesn't know b => b can't be celeb
                st.push(a);
            }
        }

        // Potential celebrity
        int ans = st.top();

        // Check row of ans: all 0s (doesn't know anyone except self)
        for (int i = 0; i < n; i++) {
            if (i != ans && mat[ans][i] == 1) {
                return -1;
            }
        }

        // Check column of ans: all 1s (everyone knows him)
        for (int i = 0; i < n; i++) {
            if (i != ans && mat[i][ans] == 0) {
                return -1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example input:
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int result = sol.celebrity(mat);

    if (result == -1)
        cout << "No celebrity found" << endl;
    else
        cout << "Celebrity is person at index: " << result << endl;

    return 0;
}

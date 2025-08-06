//85. Maximal Rectangle
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
    // Function to find the next smaller element for each bar
    vector<int> nextSmaller(vector<int>& arr, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    // Function to find the previous smaller element for each bar
    vector<int> prevSmaller(vector<int>& arr, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    // Function to calculate largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights, int n) {
        vector<int> next = nextSmaller(heights, n);
        vector<int> prev = prevSmaller(heights, n);

        int area = 0;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            if (next[i] == -1) next[i] = n;

            int width = next[i] - prev[i] - 1;
            int currentArea = height * width;
            area = max(area, currentArea);
        }
        return area;
    }

public:
    // Main function to find the maximal rectangle in a binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        // Initialize histogram for the first row
        vector<int> heights(m, 0);
        for (int j = 0; j < m; j++) {
            heights[j] = matrix[0][j] - '0';  // convert '0'/'1' to int
        }

        int area = largestRectangleArea(heights, m);

        // Process remaining rows
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            area = max(area, largestRectangleArea(heights, m));
        }

        return area;
    }
};

//84. Largest Rectangle in Histogram
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextsmaller(vector<int>& arr, int n) {
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

    vector<int> prevsmaller(vector<int>& arr, int n) {
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

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next = nextsmaller(heights, n);
        vector<int> prev = prevsmaller(heights, n);

        int area = 0;
        for (int i = 0; i < n; i++) {
            int height = heights[i];

            if (next[i] == -1) {
                next[i] = n;  // If no smaller to right, assume end of array
            }

            int width = next[i] - prev[i] - 1;
            int currentArea = height * width;
            area = max(area, currentArea);
        }

        return area;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = sol.largestRectangleArea(heights);

    cout << "Largest Rectangle Area = " << result << endl;

    return 0;
}

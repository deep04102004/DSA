#include <iostream>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if (k > (int)q.size()) {
            return q;
        }

        stack<int> st;

        // Step 1: Push first k elements into stack
        for (int i = 0; i < k; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Push stack elements back into queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move remaining elements (n-k) from front to back
        int n = q.size() - k;
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    Solution s;
    queue<int> ans = s.reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    return 0;
}

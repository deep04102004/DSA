#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    queue<int> rearrangeQueue(queue<int> q) {
        queue<int> st;  // helper queue
        int n = q.size();

        // store first half in helper
        for (int i = 0; i < n / 2; i++) {
            st.push(q.front());
            q.pop();
        }

        // interleave both halves
        while (!st.empty()) {
            q.push(st.front());
            st.pop();

            if (!q.empty()) {  // handle odd length safely
                q.push(q.front());
                q.pop();
            }
        }
        return q;
    }
};

int main() {
    Solution sol;
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    queue<int> ans = sol.rearrangeQueue(q);

    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    return 0;
}

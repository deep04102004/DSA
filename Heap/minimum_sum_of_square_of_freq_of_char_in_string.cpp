//Game with String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minValue(string &s, int k) {
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a']++;
        }

        priority_queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                q.push(freq[i]);
        }

        while (k-- && !q.empty()) {
            int a = q.top();
            q.pop();
            a -= 1;
            if (a != 0)
                q.push(a);
        }

        int ans = 0;
        while (!q.empty()) {
            ans += (q.top() * q.top());
            q.pop();
        }

        return ans;
    }
};

int main() {
    string s = "abccc";
    int k = 1;
    Solution sol;
    int result = sol.minValue(s, k);
    cout << "Minimum value after " << k << " operations: " << result << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string &s) {
        unordered_map<char,int> count;
        queue<char> q;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // increase count of current character
            count[ch]++;

            // push into queue
            q.push(ch);

            // remove all characters that are repeating
            while (!q.empty()) {
                if (count[q.front()] > 1) {
                    q.pop();
                } else {
                    ans.push_back(q.front());
                    break;
                }
            }

            // if queue becomes empty, no non-repeating char
            if (q.empty()) {
                ans.push_back('#');
            }
        }

        return ans;
    }
};

int main() {
    string s = "aabc";
    Solution sol;
    string result = sol.FirstNonRepeating(s);

    cout << "Input: " << s << endl;
    cout << "Output: " << result << endl;

    return 0;
}

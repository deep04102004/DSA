//2068. Check Whether Two Strings are Almost Equivalent
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for (char& ch : word1) v1[ch - 'a']++;
        for (char& ch : word2) v2[ch - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (abs(v1[i] - v2[i]) > 3) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string word1 = "abcde";
    string word2 = "aabbzz";
    bool result = sol.checkAlmostEquivalent(word1, word2);
    cout << "Are words almost equivalent? " << (result ? "Yes" : "No") << endl;
    return 0;
}

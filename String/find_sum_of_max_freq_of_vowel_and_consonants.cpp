//3541. Find Most Frequent Vowel and Consonant
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool isvowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || 
                ch == 'o' || ch == 'u');
    }

public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        int maxvowel = 0, maxconst = 0;

        for (char& ch : s) {
            int idx = ch - 'a';
            int count = ++freq[idx];

            if (isvowel(ch)) {
                maxvowel = max(maxvowel, count);
            } else {
                maxconst = max(maxconst, count);
            }
        }
        return maxvowel + maxconst;
    }
};

int main() {
    Solution sol;
    string s = "leetcode";  
    cout << sol.maxFreqSum(s) << endl;  // Output: 4 (2 for 'e' + 2 for 't'/'c'/'d')
    return 0;
}

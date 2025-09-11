//2785. Sort Vowels in a String
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    bool isvowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    string sortVowels(string s) {
        string t = "";
        vector<char> vowels;

        // Collect vowels
        for (char &ch : s) {
            if (isvowel(ch)) {
                vowels.push_back(ch);
            }
        }

        // Sort vowels
        sort(vowels.begin(), vowels.end());

        // Replace vowels in sorted order
        int i = 0;
        for (char &ch : s) {
            if (isvowel(ch)) {
                t += vowels[i++];
            } else {
                t += ch;
            }
        }
        return t;
    }
};

int main() {
    Solution sol;
    string s = "LeetCode";
    cout << sol.sortVowels(s) << endl;  // Expected Output: "LeotCede"
    return 0;
}

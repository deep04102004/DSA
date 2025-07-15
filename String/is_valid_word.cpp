/* 3136. Valid Word
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3) {
            return false;
        }

        string vowellist = "aeiouAEIOU";
        int vowel = 0, conso = 0;
        int i = 0;

        while (i < n) {
            char c = word[i];
            if (isalpha(c)) {
                if (vowellist.find(c) != string::npos) {
                    vowel++;
                } else {
                    conso++;
                }
            } else if (!isdigit(c)) {
                // not a letter and not a digit → invalid
                return false;
            }
            i++;
        }

        return vowel >= 1 && conso >= 1;
    }
};

int main() {
    Solution sol;

    string word = "ab1"; 
    bool result = sol.isValid(word);  

    cout << word << " -> " << (result ? "true" : "false") << endl;   //output:true

    return 0;
}

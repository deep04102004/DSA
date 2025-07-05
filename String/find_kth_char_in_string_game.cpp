//3304. Find the K-th Character in String Game I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        int n = word.size();
        while (n < k) {
            string curr = word;
            for (char ch : curr) {
                word += ch + 1;
            }
            n = word.size();
        }
        return word[k - 1];
    }
};

int main() {
    Solution sol;
    int k = 5;
    cout << "The " << k << "th character is: " << sol.kthCharacter(k) << endl; //output:b
    return 0;
}

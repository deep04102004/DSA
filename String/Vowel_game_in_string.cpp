//3227. Vowels Game in a String
#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        for (char& ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
        }
        return false; 
    }
};

int main() {
    Solution sol;
    string s = "bcdfg";

    if (sol.doesAliceWin(s)) {
        cout << "Alice wins (vowel present)" << endl;
    } else {
        cout << "Alice loses (no vowel)" << endl;
    }

    return 0;
}

//58. Length of Last Word
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        int ans = 0;

        while (i >= 0 && s[i] == ' ') i--;       // Skip trailing spaces
        while (i >= 0 && s[i] != ' ') {          // Count the last word
            ans++;
            i--;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "Hello World  ";
    int result = sol.lengthOfLastWord(s);
    cout << "Length of last word: " << result << endl;
    return 0;
}

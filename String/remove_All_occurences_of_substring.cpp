#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Keep removing 'part' from 's' until it no longer exists
        while (s.size() != 0 && s.find(part) < s.size()) {
            s.erase(s.find(part), part.size());
        }
        return s;
    }
};

int main() {
    Solution sol;

    string s = "daabcbaabcbc";
    string part = "abc";

    string result = sol.removeOccurrences(s, part);

    cout << "Result after removing occurrences: " << result << endl;

    return 0;
}

//Parenthesis Checker (GFG)
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isBalanced(string& k) {
        stack<char> s;

        for (char ch : k) {
            if (ch == '(' || ch == '{' || ch == '[') {
                s.push(ch);
            } 
            else {
                if (!s.empty()) {
                    if ((ch == ')' && s.top() == '(') || 
                        (ch == '}' && s.top() == '{') || 
                        (ch == ']' && s.top() == '[')) {
                        s.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return s.empty();
    }
};

int main() {
    Solution sol;
    string s = "{[()]}";

    if (sol.isBalanced(s)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}

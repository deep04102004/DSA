//921. Minimum Add to Make Parentheses Valid
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to find the minimum number of parentheses to add to make the string valid
int minAddToMakeValid(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        }
        else {
            if (!st.empty() && st.top() == '(') {
                st.pop(); // match found
            }
            else {
                st.push(ch); // unmatched ')'
            }
        }
    }

    return st.size(); // unmatched parentheses count
}

int main() {
    string s = "(()))(";
    int result = minAddToMakeValid(s);
    cout << "Minimum parentheses to add: " << result << endl;
    return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check redundancy of brackets
bool checkRedundancy(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else {
            if (ch == ')') {
                bool isRedundant = true;

                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }

                // Pop the opening bracket
                if (!st.empty()) {
                    st.pop();
                }

                if (isRedundant) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    string expr1 = "((a+b))";
    string expr2 = "(a+(b)/c)";
    string expr3 = "(a+b*(c-d))";

    cout << expr1 << " → " << (checkRedundancy(expr1) ? "Redundant" : "Not Redundant") << endl;
    cout << expr2 << " → " << (checkRedundancy(expr2) ? "Redundant" : "Not Redundant") << endl;
    cout << expr3 << " → " << (checkRedundancy(expr3) ? "Redundant" : "Not Redundant") << endl;

    return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int countMinReversals(string s) {
    // If length is odd, we can't balance it
    if (s.length() % 2 != 0) {
        return -1;
    }

    stack<char> st;

    for (char ch : s) {
        if (ch == '{') {
            st.push(ch);
        } else {
            if (!st.empty() && st.top() == '{') {
                st.pop(); // valid pair
            } else {
                st.push(ch); // unmatched closing
            }
        }
    }

    // Count unmatched opening and closing brackets
    int a = 0, b = 0;
    while (!st.empty()) {
        if (st.top() == '{') a++;
        else b++;
        st.pop();
    }

    // Each two unmatched can be fixed with 1 reversal
    int operations = (a + 1) / 2 + (b + 1) / 2;
    return operations;
}

int main() {
    string s;
    cout << "Enter expression with only '{' and '}': ";
    cin >> s;

    int result = countMinReversals(s);
    if (result == -1) {
        cout << "Cannot be balanced (odd length)." << endl;
    } else {
        cout << "Minimum reversals needed: " << result << endl;
    }

    return 0;
}

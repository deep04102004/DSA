#include <iostream>
#include <stack>
using namespace std;

// Recursive helper function
void solve(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    solve(st, x); // Insert x at bottom

    st.push(num); // Push back after recursion
}

// Function to insert x at bottom
stack<int> insertAtBottom(stack<int> st, int x) {
    solve(st, x);
    return st;
}

// Utility function to print stack (from top to bottom)
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);

    int x = 0; // Element to insert at bottom

    st = insertAtBottom(st, x);

    cout << "Stack after inserting " << x << " at bottom: ";
    printStack(st);  // Expected: 1 2 3 0 (top to bottom)
    
    return 0;
}

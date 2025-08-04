#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert an element into the sorted stack
void sortedInserted(stack<int>& s, int num) {
    if (s.empty() || num > s.top()) {
        s.push(num);
        return;
    }

    int a = s.top();
    s.pop();

    sortedInserted(s, num);

    s.push(a);
}

// Recursive function to sort the stack
void sortStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int num = s.top();
    s.pop();

    sortStack(s);

    sortedInserted(s, num);
}

// Function to print the stack from top to bottom
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    cout << "Original stack (top to bottom): ";
    printStack(s);

    // Reconstruct stack again for sorting (since printStack empties it)
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    sortStack(s);

    cout << "Sorted stack (top to bottom): ";
    printStack(s);

    return 0;
}

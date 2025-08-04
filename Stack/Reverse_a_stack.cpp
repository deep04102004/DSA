#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertatbottom(stack<int>& St, int num) {
    if (St.empty()) {
        St.push(num);
        return;
    }

    int a = St.top();
    St.pop();

    insertatbottom(St, num);

    St.push(a);
}

// Recursive function to reverse the stack
void Reverse(stack<int>& St) {
    if (St.empty()) {
        return;
    }

    int num = St.top();
    St.pop();

    Reverse(St);

    insertatbottom(St, num);
}

// Function to print stack from top to bottom
void printStack(stack<int> St) {
    while (!St.empty()) {
        cout << St.top() << " ";
        St.pop();
    }
    cout << endl;
}

int main() {
    stack<int> St;

    // Push elements into the stack
    St.push(1);
    St.push(2);
    St.push(3);
    St.push(4);

    cout << "Original stack (top to bottom): ";
    printStack(St);

    // Recreate the stack since it's empty now
    St.push(1);
    St.push(2);
    St.push(3);
    St.push(4);

    Reverse(St);

    cout << "Reversed stack (top to bottom): ";
    printStack(St);

    return 0;
}
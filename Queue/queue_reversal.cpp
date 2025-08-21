#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> st;

        // Move all elements from queue to stack
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }

        // Move all elements back from stack to queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        return q;
    }
};

// Helper function to print queue
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    Solution sol;
    queue<int> q;

    // Example queue: 1 2 3 4 5
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original Queue: ";
    printQueue(q);

    // Reverse the queue
    q = sol.reverseQueue(q);

    cout << "Reversed Queue: ";
    printQueue(q);

    return 0;
}

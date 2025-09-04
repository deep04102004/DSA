//232. Implement Queue using Stacks
#include <iostream>
#include<stack>
using namespace std;

class MyQueue {
private:
    stack<int> instack;
    stack<int> outstack;

    // Transfer elements only when outstack is empty
    void transfer() {
        while (!instack.empty()) {
            outstack.push(instack.top());
            instack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        instack.push(x);
    }

    int pop() {
        if (outstack.empty()) {
            transfer();
        }
        int val = outstack.top();
        outstack.pop();
        return val;
    }

    int peek() {
        if (outstack.empty()) {
            transfer();
        }
        return outstack.top();
    }

    bool empty() {
        return instack.empty() && outstack.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.pop() << endl;   // 10
    cout << q.peek() << endl;  // 20
    cout << q.empty() << endl; // 0 (false)

    q.pop(); // removes 20
    q.pop(); // removes 30
    cout << q.empty() << endl; // 1 (true)

    return 0;
}

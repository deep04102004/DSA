//155. Min Stack
#include<iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> s;
    long long mini;

public:
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            mini = val;
        } else {
            if (val < mini) {
                s.push(2LL * val - mini); // store encoded value
                mini = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        long long curr = s.top();
        s.pop();
        if (curr < mini) {
            mini = 2LL * mini - curr; // restore old minimum
        }
    }

    int top() {
        long long curr = s.top();
        if (curr < mini) {
            return (int)mini; // real top value is mini
        }
        return (int)curr;
    }

    int getMin() {
        return (int)mini;
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << "\n"; // -3
    obj->pop();
    cout << obj->top() << "\n";    // 0
    cout << obj->getMin() << "\n"; // -2

    delete obj;
    return 0;
}

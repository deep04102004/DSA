//225. Implement Stack using Queues
#include <iostream>
#include<queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() {
        // constructor does not need initialization
    }
    
    void push(int x) {
        q.push(x);
        // rotate the queue so that the new element is at the front
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    // Example usage
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Top element: " << st.top() << endl; // should be 3
    cout << "Pop element: " << st.pop() << endl; // should remove 3
    cout << "Top element: " << st.top() << endl; // should be 2

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    st.pop(); // remove 2
    st.pop(); // remove 1
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}

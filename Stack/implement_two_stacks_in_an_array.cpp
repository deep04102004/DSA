#include <iostream>
using namespace std;

class twoStacks {
public:
    int* arr;
    int top1;
    int top2;
    int size;

    // Default constructor with size 100
    twoStacks() {
        size = 100;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    // Push into stack1
    void push1(int x) {
        if ((top2 - top1) > 1) {
            top1++;
            arr[top1] = x;
        }
    }

    // Push into stack2
    void push2(int x) {
        if ((top2 - top1) > 1) {
            top2--;
            arr[top2] = x;
        }
    }

    // Pop from stack1
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            return -1;
        }
    }

    // Pop from stack2
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            return -1;
        }
    }

    // Destructor to avoid memory leak
    ~twoStacks() {
        delete[] arr;
    }
};

int main() {
    twoStacks ts;

    // Push some values to both stacks
    ts.push1(10);
    ts.push1(20);
    ts.push2(30);
    ts.push2(40);

    // Pop and print from both stacks
    cout << "Popped from stack1: " << ts.pop1() << endl; // 20
    cout << "Popped from stack1: " << ts.pop1() << endl; // 10
    cout << "Popped from stack2: " << ts.pop2() << endl; // 40
    cout << "Popped from stack2: " << ts.pop2() << endl; // 30
    cout << "Popped from empty stack1: " << ts.pop1() << endl; // -1

    return 0;
}

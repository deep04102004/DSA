//622. Design Circular Queue
#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    vector<int> arr;
    int front;
    int rear;
    int size;
    int count;
public:
    MyCircularQueue(int k) {
        arr.resize(k);
        front = 0;
        rear = -1;
        count = 0;
        size = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % size;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

int main() {
    MyCircularQueue q(3);  // queue of size 3
    
    cout << q.enQueue(1) << endl; // true
    cout << q.enQueue(2) << endl; // true
    cout << q.enQueue(3) << endl; // true
    cout << q.enQueue(4) << endl; // false (full)
    
    cout << q.Rear() << endl;     // 3
    cout << q.isFull() << endl;   // true
    
    cout << q.deQueue() << endl;  // true
    cout << q.enQueue(4) << endl; // true
    cout << q.Rear() << endl;     // 4
}

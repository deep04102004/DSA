#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// helper to insert at tail
void insertAtTail(Node*& tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* segregate(Node* head) {
    Node* zero = new Node(-1);
    Node* zerotail = zero;
    Node* one = new Node(-1);
    Node* onetail = one;
    Node* two = new Node(-1);
    Node* twotail = two;

    Node* curr = head;

    while (curr != NULL) {
        int val = curr->data;
        if (val == 0) {
            insertAtTail(zerotail, curr);
        } else if (val == 1) {
            insertAtTail(onetail, curr);
        } else { // val == 2
            insertAtTail(twotail, curr);
        }
        curr = curr->next;
    }

    // connect the three lists
    if (one->next != NULL) {
        zerotail->next = one->next;
    } else {
        zerotail->next = two->next;
    }
    onetail->next = two->next;
    twotail->next = NULL;

    head = zero->next;

    delete zero;
    delete one;
    delete two;

    return head;
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    cout << "Original list: ";
    printList(head);

    head = segregate(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}

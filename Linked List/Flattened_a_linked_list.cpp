#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
private:
    Node* merge(Node* down, Node* right) {
        if (down == NULL) return right;
        if (right == NULL) return down;

        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while (down && right) {
            if (down->data < right->data) {
                temp->bottom = down;
                temp = down;
                down = down->bottom;
                temp->next = NULL; // break horizontal link
            } else {
                temp->bottom = right;
                temp = right;
                right = right->bottom;
                temp->next = NULL; // break horizontal link
            }
        }

        while (down) {
            temp->bottom = down;
            temp = down;
            down = down->bottom;
            temp->next = NULL;
        }

        while (right) {
            temp->bottom = right;
            temp = right;
            right = right->bottom;
            temp->next = NULL;
        }

        return dummy->bottom;
    }

public:
    Node* flatten(Node* root) {
        if (root == NULL || root->next == NULL) {
            return root;
        }

        // Recursively flatten the rest of the list
        root->next = flatten(root->next);

        // Merge current list with the already-flattened right side
        root = merge(root, root->next);

        return root;
    }
};

// Helper to print flattened list
void printFlattened(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {
    /*
    Building the following linked structure:

    5 -> 10 -> 19 -> 28
    |    |     |     |
    7    20    22    35
    |          |     |
    8          50    40
    |                |
    30               45
    */

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution sol;
    Node* flat = sol.flatten(head);

    printFlattened(flat);

    return 0;
}

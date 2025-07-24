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

class Solution {
public:
    // Reverse a linked list
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    // Insert at tail of a linked list
    void insertattail(Node*& head, Node*& tail, int d) {
        Node* temp = new Node(d);
        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }

    // Add two reversed lists
    Node* add(Node* num1, Node* num2) {
        int carry = 0;
        Node* anshead = NULL;
        Node* anstail = NULL;

        while (num1 != NULL || num2 != NULL || carry != 0) {
            int val1 = 0;
            if (num1 != NULL) {
                val1 = num1->data;
            }
            int val2 = 0;
            if (num2 != NULL) {
                val2 = num2->data;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertattail(anshead, anstail, digit);
            carry = sum / 10;

            if (num1 != NULL) num1 = num1->next;
            if (num2 != NULL) num2 = num2->next;
        }
        return anshead;
    }

    // Remove leading zeros
    Node* removeLeadingZeros(Node* head) {
        while (head != NULL && head->data == 0 && head->next != NULL) {
            head = head->next;
        }
        return head;
    }

    // Main function to add two lists
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* rev1 = reverse(num1);
        Node* rev2 = reverse(num2);

        Node* ans = add(rev1, rev2);
        ans = reverse(ans);
        ans = removeLeadingZeros(ans);

        return ans;
    }
};

// Helper to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " ";
        head = head->next;
    }
    cout << "\n";
}

// Helper to create a linked list from vector
Node* createList(const vector<int>& digits) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int d : digits) {
        Node* temp = new Node(d);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

int main() {
    // Example:
    // num1 = 9->9->9
    // num2 = 1
    // Output should be: 1->0->0->0

    vector<int> v1 = {9, 9, 9};
    vector<int> v2 = {1};

    Node* num1 = createList(v1);
    Node* num2 = createList(v2);

    Solution sol;
    Node* ans = sol.addTwoLists(num1, num2);

    cout << "Result: ";
    printList(ans);

    return 0;
}

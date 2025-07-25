//138. Copy List with Random Pointer

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    // helper to insert a new node at the tail of a list
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

public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // step1: Make Clone Nodes (separate linear list first)
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;
        while (temp != NULL) {
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }

        // step2: Place clone nodes in between original nodes
        Node* origi_node = head;
        Node* clonenode = clonehead;
        while (origi_node != NULL && clonenode != NULL) {
            Node* nxt1 = origi_node->next;
            origi_node->next = clonenode;
            origi_node = nxt1;

            nxt1 = clonenode->next;
            clonenode->next = origi_node;
            clonenode = nxt1;
        }

        // step3: Assign random pointers for cloned nodes
        temp = head;
        while (temp != NULL) {
            if (temp->next) {
                temp->next->random = temp->random ? temp->random->next : NULL;
            }
            temp = temp->next->next;
        }

        // step4: Revert changes (separate original and cloned lists)
        origi_node = head;
        clonenode = clonehead;
        while (origi_node != NULL && clonenode != NULL) {
            origi_node->next = clonenode->next;
            origi_node = origi_node->next;
            if (origi_node != NULL) {
                clonenode->next = origi_node->next;
            }
            clonenode = clonenode->next;
        }

        // step5: return cloned head
        return clonehead;
    }
};

// Helper to print list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Val: " << temp->val << ", Random: ";
        if (temp->random) cout << temp->random->val;
        else cout << "NULL";
        cout << "\n";
        temp = temp->next;
    }
}

int main() {
    // Build a test list: 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2;
    n2->next = n3;

    // Assign random pointers
    n1->random = n3; // 1's random -> 3
    n2->random = n1; // 2's random -> 1
    n3->random = n3; // 3's random -> itself

    cout << "Original list:\n";
    printList(n1);

    Solution sol;
    Node* clonedHead = sol.copyRandomList(n1);

    cout << "\nCloned list:\n";
    printList(clonedHead);

    return 0;
}

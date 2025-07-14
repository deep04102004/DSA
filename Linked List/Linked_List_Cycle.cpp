//141. Linked List Cycle

#include <iostream>
using namespace std;

// Node definition
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Function to detect cycle in a linked list
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Main function to test
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Uncomment below line to create a cycle (4 -> 2)
     //head->next->next->next->next = head->next;

    if (hasCycle(head)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}

//160. Intersection of Two Linked Lists
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode *t1 = headA;
        ListNode *t2 = headB;

        while (t1 != t2) {
            t1 = (t1 == NULL) ? headB : t1->next;
            t2 = (t2 == NULL) ? headA : t2->next;
        }

        return t1; // Either intersection node or NULL
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list A: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    // Create list B: 9 -> 4 -> 5 (intersects with A at node 4)
    ListNode* headB = new ListNode(9);
    headB->next = headA->next->next->next; // Point B's next to node 4 of list A

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection Node: " << intersection->val << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}

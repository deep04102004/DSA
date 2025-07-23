//21. Merge Two Sorted Lists
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
public:
    Node* solve(Node* list1, Node* list2) {
        Node* curr1 = list1;
        Node* next1 = curr1->next;
        Node* curr2 = list2;
        Node* next2 = nullptr;

        // handle case when list1 has only one node
        if (next1 == nullptr) {
            curr1->next = curr2;
            return list1;
        }

        while (next1 != nullptr && curr2 != nullptr) {
            if (curr1->data <= curr2->data && curr2->data <= next1->data) {
                //Add Node between List1
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                
                //update pointers 
                curr1 = curr2;
                curr2 = next2;
            } 
            
            else {
                //move pointers forward
                curr1 = next1;
                next1 = next1->next;

                if (next1 == nullptr) {
                    curr1->next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }

    Node* mergeTwoLists(Node* list1, Node* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->data < list2->data) {
            return solve(list1, list2);
        } else {
            return solve(list2, list1);
        }
    }
};

//Print Function 
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    Node* list1 = new Node(2);
    Node* list2 = new Node(1);

    Solution sol;
    Node* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged list: ";
    printList(merged);

    // Another test: list3 = [1->3->5], list4 = [2->4->6]
    Node* list3 = new Node(1);
    list3->next = new Node(3);
    list3->next->next = new Node(5);

    Node* list4 = new Node(2);
    list4->next = new Node(4);
    list4->next->next = new Node(6);

    Node* merged2 = sol.mergeTwoLists(list3, list4);
    cout << "Merged list: ";
    printList(merged2);

    return 0;
}

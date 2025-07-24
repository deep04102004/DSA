//234. Palindrome Linked List
#include <iostream>
using namespace std;

// Node class
class node {
public:
    int data;
    node* next;

    node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

// Find middle of linked list
node* middle(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Reverse a linked list
node* reverselist(node* head) {
    node* prev = NULL;
    node* curr = head;

    while (curr != NULL) {
        node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

// Check if list is palindrome
bool isPalindrome(node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // find middle
    node* middlenode = middle(head);

    // reverse second half
    node* temp = middlenode->next;
    middlenode->next = reverselist(temp);

    // compare first and second halves
    node* head1 = head;
    node* head2 = middlenode->next;
    while (head2 != NULL) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

// Print linked list
void printList(node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Create a palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(1);

    cout << "Original list: ";
    printList(head);

    cout << "Is palindrome? " << (isPalindrome(head) ? "true" : "false") << "\n";

    // Another list: 1 -> 2 -> 3 (not palindrome)
    node* head2 = new node(1);
    head2->next = new node(2);
    head2->next->next = new node(3);

    cout << "Original list: ";
    printList(head2);

    cout << "Is palindrome? " << (isPalindrome(head2) ? "true" :"false")<<"\n";

    return 0;
}

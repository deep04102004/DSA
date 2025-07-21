#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* removeDuplicates(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    unordered_set<int> st;

    while (curr != NULL) {
        if (st.count(curr->data)) {
            prev->next = curr->next;
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        } else {
            st.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

//Function For Print a List 
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 2 -> 4 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(3);

    cout << "Original list:\n";
    for (Node* t = head; t != NULL; t = t->next) cout << t->data << " ";
    cout << "\n";

    head = removeDuplicates(head);

    print(head);

    return 0;
}

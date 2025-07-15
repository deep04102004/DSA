//876. Middle of the Linked List

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// Function to find middle node
ListNode *middleNode(ListNode *head)
{
    ListNode *temp = head;
    int cnt = 0;

    // Count length of list
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    cout << "Length of list: " << cnt << endl;

    // Find middle index
    int n = cnt / 2;

    // Traverse to middle
    temp = head;
    int cnt1 = 0;
    while (cnt1 < n)
    {
        temp = temp->next;
        cnt1++;
    }
    return temp;
}

// Print entire linked list
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Create sample list: 1->2->3->4->5->NULL
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    print(head);

    // Get middle node
    ListNode *mid = middleNode(head);

    cout << "Middle Node onwards: ";
    print(mid); // prints from middle to end

    return 0;
}

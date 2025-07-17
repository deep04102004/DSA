// 25. Reverse Nodes in k-Group

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

//Reverse K Group Function
node *ReverseKgroup(node *&head, int k)
{
    node *temp = head;
    int count1 = 0;
    while (temp != NULL)
    {
        count1++;
        temp = temp->next;
    }

    if (head == NULL || head->next == NULL || count1 < k)
    {
        return head;
    }

    node *curr = head;
    node *prev = NULL;
    node *forward = NULL;

    int count2 = 0;

    while (curr != NULL && count2 < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;         // Move prev Forward
        curr = forward;      // Move curr Forward

        count2++;
    }

    head->next = ReverseKgroup(forward, k);    // reverse rest of the list by recursion
    return prev;
}

//Print Function
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    int k = 2;

    node *ans = ReverseKgroup(head, k);
    print(ans);

    return 0;
}
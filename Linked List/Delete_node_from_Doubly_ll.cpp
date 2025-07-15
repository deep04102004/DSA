#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Delete Function
void deleteatpos(node *&head, int pos)
{
    if (pos == 1)
    {
        node *temp = head;
        head = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        int cnt = 1;

        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;

            cnt++;
        }
        if (curr->next != NULL)
        {
            curr->next->prev = curr->prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}
// insert Function
void insertatpos(node *&head, int pos, int d)
{
    if (pos == 1)
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;

        return;
    }
    int cnt = 1;
    node *temp = head;
    while (cnt < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL)
    {
        cout << "Position is out of range";
        return;
    }

    node *new_node = new node(d);
    new_node->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Print Function
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    node *head = new node(1);

    insertatpos(head, 2, 2);
    insertatpos(head, 3, 3);
    insertatpos(head, 4, 4);
    insertatpos(head, 5, 5);

    cout << "Linked List Before Delete: " << endl;
    print(head);
    deleteatpos(head, 5);
    cout << "Linked List After Delete: " << endl;
    print(head);
}
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

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

// Insert At Position Function
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

int main()
{
    node *head = new node(10);

    insertatpos(head, 2, 12);
    insertatpos(head, 2, 11);
    insertatpos(head, 4, 13);
    insertatpos(head, 5, 14);

    print(head);
}
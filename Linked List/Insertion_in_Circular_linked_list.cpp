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

void insert(node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        node *new_node = new node(d);
        new_node->next = new_node;
        tail = new_node;
       
    }

    else
    {
        node *new_node = new node(d);
        node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        new_node->next = curr->next;
        curr->next = new_node;

        if (curr == tail)
        {
            tail = new_node;
        }
    }
}

void print(node *tail)
{
    node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
}

int main()
{
    node *tail = NULL;

    insert(tail, 0, 2);
    insert(tail, 2, 2);
    insert(tail, 2, 3);
    insert(tail, 3, 7);
    insert(tail, 3, 1);
    insert(tail, 1, 5);
    insert(tail, 3, 7);
    print(tail);
}
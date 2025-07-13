#include <bits/stdc++.h>
using namespace std;

//node of linked Lst
class node
{
public:
    int data;
    node *next;
    
    //constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    
    //Destructor
    ~node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

//Delete Function
void deleteatpos(node *&head, int pos)
{

    if (pos == 1)
    {
        node*temp=head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    else{
        node*curr=head;
        node*prev=NULL;

        int cnt=1;

        while(cnt<pos){
            prev=curr;
            curr=curr->next;

            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

//Insert Function
void Insert(node *&head, int pos, int d)
{
    node *new_node = new node(d);

    if (pos == 1)
    {
        new_node->next = head;
        head = new_node;
        return;
    }

    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1 && temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Position is out of range";
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

//Print Function
void print(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int main()
{
    node *head = new node(1);

    Insert(head,2,2);
    Insert(head,3,3);
    Insert(head,4,4);
    Insert(head,5,5);

    cout<<"List Before Delete: ";
    print(head);

    deleteatpos(head,3);

    cout<<"List After Delete: ";
    print(head);
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

//Node Class
class node{
    public:
    int data;
    node *next;

    node(int d){
        this->data=d;
        this->next=NULL;
    }
};

//Insert Function
void insert(node*&tail,int element,int d){
    if(tail==NULL){
        node*new_node=new node(d);
        new_node->next=new_node;
        tail=new_node;
    }

    else{
        node*new_node=new node(d);
        node*curr=tail;

        while(curr->data!=element){
            curr=curr->next;
        }

        new_node->next=curr->next;
        curr->next=new_node;
        if (curr == tail)
        {
            tail = new_node;
        }
    }
}

//Delete Function
void delete_node(node*&tail, int element){
    if(tail==NULL){             //if list is empty
        cout<<"List Is Empty";
    }
    
    else{
        node*prev=tail;
        node*curr=prev->next;

        if(tail==prev){    //If list has only one node
            tail=NULL;
            return;
        }

        while(curr->data != element){
            curr=curr->next;
            prev=prev->next;
        }

        prev->next=curr->next;
        curr->next=NULL;
        if(curr==tail){
            tail=prev;
        }
        delete curr;
    }
}

//Print Function
void print(node* tail){
    node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout<<endl;
}

int main(){
     node*tail=NULL;

     insert(tail,5,1);
    //  insert(tail,1,5);
    //  insert(tail,1,2);
    //  insert(tail,5,6);
    //  insert(tail,2,7);

     cout<<"Before Delete "<<endl;
     print(tail);
    
     delete_node(tail,1);

     cout<<"After Delete: "<<endl;
     print(tail);
}
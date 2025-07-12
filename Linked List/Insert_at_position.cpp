#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node*next;

        node(int data){
            this->data=data;
            this->next=NULL;
        }
};

void InsertatPos(node*&head,int pos,int d){
    node*new_node=new node(d);

    if(pos==1){
        new_node->next=head;
        head=new_node;
        return;
    }

    node*temp=head;
    int cnt=1;
    while(cnt<pos-1 && temp!=NULL){
        cnt++;
        temp=temp->next;
    }

    if(temp==NULL){
        cout<<"Position is out of range";
        return;
    }

    new_node->next=temp->next;
    temp->next=new_node;
}

void print(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int main(){     
     node*head=new node(2)  ;
     InsertatPos(head,2,3);
     InsertatPos(head,1,1);
     InsertatPos(head,4,4);
     InsertatPos(head,5,5);
     
     print(head);
    
}
#include<iostream>
using namespace std;
class node{
  public:
    int data;
    node* left;
    node* right;

    node(int d){
       this->data = d;
       this->left = NULL;
       this->right = NULL;
    }

    
};

node* buildtree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    root = new node(data);
    
    
    cout<<"Enter data for Left Node "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter data for right node "<<data<<endl;
    root->right = buildtree(root->right);

    return root;
}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node* root = NULL;
    root = buildtree(root); //input: 12 13 15 -1 -1 16 -1 -1 14 17 -1 -1 -1
    preorder(root); //output : 12 13 15 16 14 17
    return 0;
}
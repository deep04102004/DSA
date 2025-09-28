//236. Lowest Common Ancestor of a Binary Tree
#include <iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        if(root == NULL){
            return NULL;
        }
        
        if(root->data == n1 || root->data == n2){
            return root;
        }
        
        Node*leftans = lca(root->left,n1,n2);
        Node*rightans = lca(root->right,n1,n2);
        
        if(leftans != NULL && rightans != NULL){
            return root;
        }
        else if(leftans == NULL && rightans != NULL){
            return rightans;
        }
        else if(leftans != NULL && rightans == NULL){
            return leftans;
        }
        else{
            return NULL;
        }
        
    }
};

Node* buildtree(Node* root){
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    root = new Node(data);
    
    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}

int main() {
    Node* root = NULL;
    cout<<"Enter the data: "<<endl; 
    root = buildtree(root);  //input: 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    int n1,n2;
    cout<<"Enter n1:"<<endl;  // input:15
    cin>>n1;
    cout<<"Enter n2: "<<endl;  // input : 7
    cin>>n2;
    Solution sol;
    Node* lca = sol.lca(root,n1,n2);

    cout<<"Lowest common ancestor is: "<<lca->data;  // output: 20
    return 0;
}
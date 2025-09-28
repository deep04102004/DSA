//Kth Ancestor in a Tree
#include <iostream>
#include<vector>
#include<unordered_map>
#include <climits>
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
  private:
   Node* solve(Node*root,int&k,int node){
       if(root == NULL){
           return NULL;
       }
       
       if(root->data == node){
           return root;
       }
       
       Node*leftans = solve(root->left,k,node);
       Node*rightans = solve(root->right,k,node);
       
       if(leftans != NULL && rightans == NULL){
           k--;
           
           if(k <= 0){
               k = INT_MAX;
               return root;
           }
           return leftans;
       }
       
        if(leftans == NULL && rightans != NULL){
           k--;
           
           if(k <= 0){
               k = INT_MAX;
               return root;
           }
           return rightans;
       }
       return NULL;
   }
  public:
    int kthAncestor(Node *root, int k, int node) {
        Node*ans = solve(root,k,node);
        
        if(ans == NULL || ans->data == node){
            return -1;
        }
        
        return ans->data;
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
    root = buildtree(root);  //input: 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    int node;
    cout<<"Enter the node: "<<endl; //input: 4
    cin>>node;
    int k;
    cout<<"Enter k: "<<endl;  // input:2
    cin>>k;
    Solution sol;
    int kans = sol.kthAncestor(root,k,node);

    cout<<"kth Ancestor of node is : "<<kans;  // output: 1
    return 0;
}
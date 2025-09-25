//Tree Boundary Traversal.
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
  private:
    void traverseleft(Node *root,vector<int>&ans){
        if((root == NULL) || ((root->left == NULL) && (root->right == NULL))){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            traverseleft(root->left,ans);
        }
        else{
            traverseleft(root->right,ans);
        }
    }
    
    void traverseleaf(Node *root,vector<int>&ans){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
    }
    
    void traverseright(Node *root,vector<int>&ans){
        if((root == NULL) || ((root->left == NULL) && (root->right == NULL))){
            return;
        }
        
        if(root->right){
            traverseright(root->right,ans);
        }
        else{
            traverseright(root->left,ans);
        }
        
        ans.push_back(root->data);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        
        if(root == NULL){
            return ans;
        }
        //traverse root of tree.
        ans.push_back(root->data);

        //traverse left boundary of tree.
        traverseleft(root->left,ans);

        //traverse leafs of tree.
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);

        //traverse right boundary of tree.
        traverseright(root->right,ans);
        
        return ans;
        
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

    Solution sol;
    vector<int> boundary= sol.boundaryTraversal(root);

        for(int a : boundary){
            cout<<a<<" ";     //output: 3 9 15 7 20 
        }
    return 0;
}
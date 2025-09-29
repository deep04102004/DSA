//199. Binary Tree Right Side View
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
     void solve(Node *root,vector<int>&ans,int level){
         if(root == NULL){
             return;
         }
         
         if(level == ans.size()){
             ans.push_back(root->data);
         }
         
         solve(root->right,ans,level+1);
         solve(root->left,ans,level+1);
     }
  public:
    vector<int> RightView(Node *root) {
        vector<int>ans;
        solve(root,ans,0);
        
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
    vector<int> right = sol.RightView(root);

    for(auto&a : right){
        cout<<a<<" ";   //Output: 3 20 7  
    }
    return 0;
}
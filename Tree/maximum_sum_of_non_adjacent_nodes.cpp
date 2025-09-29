//Maximum sum of Non-adjacent nodes
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
    pair<int,int>solve(Node*root){
        if(root == NULL){
            pair<int,int>p = make_pair(0,0);
            return p ;
        }
        
        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);
        
        pair<int,int>res;
        
        res.first = root->data + left.second + right.second;
        res.second = max(left.first,left.second)+max(right.first,right.second);
        
        return res;
    }
  public:
    int getMaxSum(Node *root) {
        pair<int,int>ans = solve(root);
        
        return max(ans.first,ans.second);
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
    int maxsum = sol.getMaxSum(root);

    cout<<"Maximum Sum of Non Adjacent nodes: "<<maxsum;  // output: 31
    return 0;
}
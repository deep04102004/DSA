//112. Path Sum
#include <iostream>
#include<algorithm>
#include<cmath>
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
    bool hasPathSum(Node* root, int targetSum) {
       if(root == NULL){
        return false;
       }
       if(root->left == NULL && root->right == NULL){
        return targetSum - root->data == 0;
       }

       targetSum -= root->data;

       return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
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
    root = buildtree(root);  //input: 5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1 -1 -1
    int targetsum;
    cout<<"Enter Target Sum: "<<endl; // input: 22
    cin>>targetsum;
    Solution sol;
     
    cout << (sol.hasPathSum(root,targetsum) ? "True" : "False") << endl; // output: True

    return 0;
}
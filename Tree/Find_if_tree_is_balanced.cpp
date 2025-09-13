//110. Balanced Binary Tree
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
private:
   pair<bool,int>isBalancedFast(Node* root){
       if(root == NULL){
        pair<bool,int>p = {true,0};
        return p;
       }

       pair<bool,int>left = isBalancedFast(root->left);
       pair<bool,int>right = isBalancedFast(root->right);

       bool leftans = left.first;
       bool rightans = right.first;
       bool diff = abs(left.second - right.second) <= 1;

       pair<bool,int>ans;
       ans.second = max(left.second,right.second) + 1;

       if(leftans && rightans && diff){
        ans.first = true;
       }
       else{
        ans.first = false;
       }

       return ans;
   }
public:
    bool isBalanced(Node* root) {
        return isBalancedFast(root).first;
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
    root = buildtree(root);  //input: 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1

    Solution sol;

    cout << (sol.isBalanced(root) ? "Balanced" : "Not Balanced") << endl; // output: Not Balanced

    return 0;
}